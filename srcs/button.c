/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 01:26:36 by jcanteau          #+#    #+#             */
/*   Updated: 2020/07/28 17:50:32 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	ft_closing_door(t_env *doom, int door_y, int door_x)
{
	doom->map.data[door_y * doom->map.nbcol + door_x] = DOOR;
	if ((FMOD_System_PlaySound(doom->sound.system, doom->sound.door_closing,
			NULL, 0, NULL)) != FMOD_OK)
		perror("Error in FMOD_System_PlaySound for door_closing ");
}

void	ft_search_door(t_env *doom, int door_y, int door_x)
{
	int		y;
	int		x;

	y = door_y - BUTTON_RANGE;
	while (y <= door_y + BUTTON_RANGE)
	{
		x = door_x - BUTTON_RANGE;
		while (x <= door_x + BUTTON_RANGE)
		{
			if (y > 0 && y < doom->map.nbl && x > 0 && x < doom->map.nbcol)
			{
				if (doom->map.data[y * doom->map.nbcol + x] == DOOR)
					init_door(doom, y, x);
				else if (doom->map.data[y * doom->map.nbcol + x] == DOOR_OPENED)
					ft_closing_door(doom, y, x);
				//printf("cell[%d][%d] = %c\n", y, x, doom->map.data[y * doom->map.nbcol + x]);
			}
			x++;
		}
		y++;
	}
}

void	ft_switch_button(t_env *doom)
{
	int		y;
	int		x;

	y = doom->cam.pos_y + cos(doom->cam.angle);
	x = doom->cam.pos_x + sin(doom->cam.angle);
	if (doom->map.data[y * doom->map.nbcol + x] == BUTTON_OFF)
	{
		doom->map.data[y * doom->map.nbcol + x] = BUTTON_ON;
		ft_search_door(doom, y, x);
		if ((FMOD_System_PlaySound(doom->sound.system, doom->sound.switch_on,
				NULL, 0, NULL)) != FMOD_OK)
			perror("Error in FMOD_System_PlaySound for switch_on ");
	}
	else if (doom->map.data[y * doom->map.nbcol + x] == BUTTON_ON)
	{
		doom->map.data[y * doom->map.nbcol + x] = BUTTON_OFF;
		ft_search_door(doom, y, x);
		if ((FMOD_System_PlaySound(doom->sound.system, doom->sound.switch_off,
				NULL, 0, NULL)) != FMOD_OK)
			perror("Error in FMOD_System_PlaySound for switch_off ");
	}
}
