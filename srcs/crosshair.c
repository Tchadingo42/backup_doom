/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crosshair.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 03:48:03 by jcanteau          #+#    #+#             */
/*   Updated: 2020/07/21 04:08:39 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	ft_draw_crosshair(t_env *doom)
{
	int		xpm_y;
	int		xpm_x;
	int		screen_y;
	int		screen_x;

	screen_y = H / 2 - doom->xpm[CROSSHAIR].h / 2;
	xpm_y = 0;
	while (xpm_y < doom->xpm[CROSSHAIR].h)
	{
		screen_x = W / 2 - doom->xpm[CROSSHAIR].w / 2;
		xpm_x = 0;
		while (xpm_x < doom->xpm[CROSSHAIR].w)
		{
			if (doom->xpm[CROSSHAIR].pixels[xpm_y *
					doom->xpm[CROSSHAIR].w + xpm_x] != MAGENTA)
				doom->screen_pixels[screen_y * W + screen_x] =
					doom->xpm[CROSSHAIR].pixels[xpm_y *
						doom->xpm[CROSSHAIR].w + xpm_x];
			screen_x++;
			xpm_x++;
		}
		screen_y++;
		xpm_y++;
	}
}