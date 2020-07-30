/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 21:29:29 by jcanteau          #+#    #+#             */
/*   Updated: 2020/07/30 02:54:18 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	ft_set_points(t_env *doom)
{
	doom->minimap.done = 0;
	doom->minimap.x = doom->minimap.j * doom->block;
	doom->minimap.y = doom->minimap.i * doom->block;
	doom->minimap.def_x = doom->minimap.x;
	doom->minimap.def_y = doom->minimap.y;
}

void	ft_set_tile_color(t_env *doom, Uint32 *color)
{
	if (doom->map.data[doom->minimap.i * doom->map.nbcol + doom->minimap.j] == WALL)
		*color = LIME;
	else if (doom->map.data[doom->minimap.i * doom->map.nbcol + doom->minimap.j] == EMPTY)
		*color = GRAY;
	else if (doom->map.data[doom->minimap.i * doom->map.nbcol + doom->minimap.j] == DOOR ||
			doom->map.data[doom->minimap.i * doom->map.nbcol + doom->minimap.j] == DOOR_OPENED)
		*color = BLUE;
	else if (doom->map.data[doom->minimap.i * doom->map.nbcol + doom->minimap.j] == GRID)
		*color = ORANGE;
	else if (doom->map.data[doom->minimap.i * doom->map.nbcol +
			doom->minimap.j] == BUTTON_OFF ||
			doom->map.data[doom->minimap.i * doom->map.nbcol + doom->minimap.j] == BUTTON_ON)
		*color = RED;
	else if (doom->map.data[doom->minimap.i * doom->map.nbcol + doom->minimap.j] == BARREL)
		*color = BROWN;
	else if (doom->map.data[doom->minimap.i * doom->map.nbcol + doom->minimap.j]==
			HEALTH_POTION)
		*color = WHITE;
	else
		*color = BLACK;
}

void	ft_draw_minimap_symbol(t_env *doom)
{
	Uint32	color;

	ft_set_tile_color(doom, &color);
	while (doom->minimap.done == 0)
	{
		doom->screen_pixels[doom->minimap.y * W + doom->minimap.x] = color;
		doom->minimap.x++;
		if (doom->minimap.x > doom->minimap.def_x + doom->block)
		{
			doom->minimap.x = doom->minimap.j * doom->block;
			doom->minimap.y++;
		}
		if (doom->minimap.y > doom->minimap.def_y + doom->block)
			doom->minimap.done = 1;
	}
}

void	ft_set_sdl_minimap_colors(t_env *doom)
{
	SDL_SetRenderDrawColor(doom->renderer, 255, 0, 0, 255);
	SDL_RenderDrawLine(doom->renderer, doom->cam.pos_x * doom->block,
						doom->cam.pos_y * doom->block,
						(doom->cam.pos_x + sin(doom->cam.angle)) * doom->block,
						(doom->cam.pos_y + cos(doom->cam.angle)) *
						doom->block);
	SDL_SetRenderDrawColor(doom->renderer, 255, 255, 255, 255);
	SDL_RenderDrawPoint(doom->renderer, doom->cam.pos_x * doom->block,
						doom->cam.pos_y * doom->block);
}

void	ft_draw_minimap(t_env *doom)
{
	doom->minimap.j = 0;
	while (doom->minimap.j < (int)doom->map.nbcol)
	{
		doom->minimap.i = 0;
		while (doom->minimap.i < (int)doom->map.nbl)
		{
			ft_set_points(doom);
			ft_draw_minimap_symbol(doom);
			doom->minimap.i++;
		}
		doom->minimap.j++;
	}
}
