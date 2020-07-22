/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 23:15:33 by jcanteau          #+#    #+#             */
/*   Updated: 2020/07/22 15:21:13 by chbelan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	ft_apply_textured_wall(t_thread_env *e)
{
	int	xpm_id;

	e->rc.sample_y = (double)(e->rc.y_ - e->rc.ceiling) /
												(e->rc.floor - e->rc.ceiling);
	e->rc.sample_y = fabs(e->rc.sample_y - (int)e->rc.sample_y);
	xpm_id = e->rc.orientation;
	if (e->xpm[xpm_id].pixels == NULL)
	{
		ft_apply_shaded_wall(e);
		return ;
	}
	e->rc.tmp_x = e->rc.sample_x * e->xpm[xpm_id].h;
	e->rc.tmp_y = e->rc.sample_y * e->xpm[xpm_id].w;
	if (e->xpm[xpm_id].pixels[e->rc.tmp_y * e->xpm[xpm_id].w + e->rc.tmp_x]
			== MAGENTA && xpm_id == GRID_XPM)
		return ;
	e->screen_pixels[e->rc.y_ * W + e->rc.x_] =
		e->xpm[xpm_id].pixels[e->rc.tmp_y * e->xpm[xpm_id].w + e->rc.tmp_x];
}

void	ft_apply_color_oriented_wall(t_thread_env *e)
{
	if (e->rc.orientation == NORTH)
		e->screen_pixels[e->rc.y_ *
			W + e->rc.x_] = BLUE;
	else if (e->rc.orientation == SOUTH)
		e->screen_pixels[e->rc.y_ *
			W + e->rc.x_] = RED;
	else if (e->rc.orientation == EAST)
		e->screen_pixels[e->rc.y_ *
			W + e->rc.x_] = YELLOW;
	else if (e->rc.orientation == WEST)
		e->screen_pixels[e->rc.y_ *
			W + e->rc.x_] = ORANGE;
	else if (e->rc.orientation == GRID_XPM)
		ft_apply_textured_wall(e);
}

void	ft_apply_shaded_wall(t_thread_env *e)
{
	double	shading;

	shading = 1 - e->rc.distance_towall / SHADING_DEPTH;
	if (shading < 0.1)
		shading = 0.1;
	e->screen_pixels[e->rc.y_ * W + e->rc.x_] =
			ft_rgba_to_uint32(255 * shading, 255 * shading, 255 * shading, 0);
}
