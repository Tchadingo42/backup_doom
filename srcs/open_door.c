/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_door.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 04:49:08 by czhang            #+#    #+#             */
/*   Updated: 2020/07/28 17:40:52 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

static void	anim_one_door(t_env *doom, t_door *door)
{
	t_door	*d;
	double	duration;

	duration = get_time(doom) - door->start_time;
	if (duration < DOOR_OPENING_DURATION)
	{
		d = door;
		doom->map.alt[d->y * doom->map.nbcol + d->x] = d->start_alt + duration * d->speed;
	}
	else if (duration >= DOOR_OPENING_DURATION)
	{
		doom->map.data[door->y * doom->map.nbcol + door->x] = DOOR_OPENED;
		doom->map.alt[door->y * doom->map.nbcol + door->x] = 1;
	}
}

void		animation_opening_door(t_env *doom)
{
	t_door	*door;

	door = doom->door;
	while (door)
	{
		anim_one_door(doom, door);
		door = door->next;
	}
	door = doom->door;
	while (door)
	{
		if (doom->map.data[door->y * doom->map.nbcol + door->x] == DOOR_OPENED)
		{
			doom->door = door->next;
			ft_memdel((void **)&door);
			door = doom->door;
		}
		else
			door = door->next;
	}
}

static void	new_door(t_env *doom, int door_y, int door_x, t_door *last)
{
	t_door	*d;

	if (!(d = (t_door *)ft_memalloc(sizeof(t_door))))
		ft_exit(doom, EXIT_FAILURE, "Error malloc door opening");
	if (last == NULL)
		doom->door = d;
	else if (last)
		last->next = d;
	d->start_time = get_time(doom);
	d->start_alt = doom->map.alt[door_y * doom->map.nbcol + door_x];
	d->speed = (MIN_ALTITUDE - d->start_alt) / (double)DOOR_OPENING_DURATION;
	d->x = door_x;
	d->y = door_y;
}

void		init_door(t_env *doom, int door_y, int door_x)
{
	t_door	*last;

	if ((FMOD_System_PlaySound(doom->sound.system, doom->sound.door_opening,
			NULL, 0, NULL)) != FMOD_OK)
		perror("Error in FMOD_System_PlaySound for door_opening ");
	last = doom->door;
	while (last && last->next)
		last = last->next;
	new_door(doom, door_y, door_x, last);
}

void		resolve_door(t_env *doom)
{
	int		y;
	int		x;

	y = doom->cam.pos_y + cos(doom->cam.angle);
	x = doom->cam.pos_x + sin(doom->cam.angle);
	if (doom->map.data[y * doom->map.nbcol + x] == DOOR)
		init_door(doom, y, x);
}
