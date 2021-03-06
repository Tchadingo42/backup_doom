/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 20:14:42 by jcanteau          #+#    #+#             */
/*   Updated: 2020/07/30 05:22:32 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void			ft_set_ceiling_floor(t_thread_env *e)
{
	double	scale;
	
	scale = e->cam.proj_dist * WALL_SIZE / e->rc.distance_towall;
	e->rc.floor =(e->cam.proj_dist / e->rc.distance_towall) * (e->cam.pos_z) + e->cam.angle_z;
	e->rc.ceiling = e->rc.floor - scale;
	e->rc.ceiling -= ((e->map.alt[e->rc.test_y * e->map.nbcol + e->rc.test_x] - 1)
			/ e->rc.distance_towall) * WALL_SIZE;
	//e->rc.floor -= ((e->map.alt[e->rc.test_y * e->map.nbcol + e->rc.test_x] - 1)
	//		/ e->rc.distance_towall) * WALL_SIZE;
}

void			ft_setup_view_sky(t_thread_env *e)
{
	e->rc.horizon = (e->rc.y_ - H * 1.5) - e->cam.angle_z;
	e->rc.rowdistance = (e->cam.pos_z * H) / e->rc.horizon /
		SKY_ZOOM / (e->cam.pos_z);
	//e->rc.rowdistance /= cos(e->cam.angle -
	//	e->rc.ray_angle);
}

void			ft_draw_ceiling(t_thread_env *e)
{
	if (e->wall == NON_TEXTURED || e->wall == SHADED ||
			e->xpm[SKY].pixels == NULL)
	{
		e->screen_pixels[e->rc.y_ * W + e->rc.x_] = DODGER_BLUE;
		return ;
	}
	ft_setup_view_sky(e);
	e->rc.floorx = 1.5 - (e->rc.rowdistance) *
		e->rc.eye_x + e->cam.pos_x * 0.0005;
	e->rc.floory = 1.5 - (e->rc.rowdistance) *
		e->rc.eye_y + e->cam.pos_y * 0.0005;
	e->rc.text_x = abs((int)(e->xpm[SKY].w * e->rc.floorx) % (e->xpm[SKY].w));
	e->rc.text_y = abs((int)(e->xpm[SKY].h * e->rc.floory) % (e->xpm[SKY].h));
	e->screen_pixels[e->rc.y_ * W + e->rc.x_] =
		e->xpm[SKY].pixels[e->xpm[SKY].w * e->rc.text_y + e->rc.text_x];
}

void			ft_draw_wall(t_thread_env *e)
{
	if (e->wall == TEXTURED)
		ft_apply_textured_wall(e);
	else if (e->wall == COLOR_ORIENTED)
		ft_apply_color_oriented_wall(e);
	else if (e->wall == SHADED)
		ft_apply_shaded_wall(e);
	else
		e->screen_pixels[e->rc.y_ *
			W + e->rc.x_] = WHITE;
}

void			ft_setup_view_floor(t_thread_env *e)
{
	e->rc.horizon = (e->rc.y_) - e->cam.angle_z;
	e->rc.rowdistance = (e->cam.pos_z * e->cam.proj_dist) / e->rc.horizon;
	e->rc.rowdistance /= cos(e->cam.angle -
		e->rc.ray_angle);
	e->rc.floorstepx = e->rc.rowdistance / W;
	e->rc.floorstepy = e->rc.rowdistance / W;
}

void			ft_draw_floor(t_thread_env *e)
{
	if (e->wall == NON_TEXTURED || e->wall == SHADED)
	{
		e->screen_pixels[e->rc.y_ * W + e->rc.x_] = OLIVE;
		return ;
	}
	ft_setup_view_floor(e);
	e->rc.floorx = e->cam.pos_x + e->rc.rowdistance *
		e->rc.eye_x;
	e->rc.floory = e->cam.pos_y + e->rc.rowdistance *
		e->rc.eye_y;
	e->rc.text_x = (int)(e->xpm[FLOOR].w * e->rc.floorx) % (e->xpm[FLOOR].w);
	e->rc.text_y = (int)(e->xpm[FLOOR].h * e->rc.floory) % (e->xpm[FLOOR].h);
	e->rc.floorx += e->rc.floorstepx;
	e->rc.floory += e->rc.floorstepy;
	e->screen_pixels[e->rc.y_ * W + e->rc.x_] =
		e->xpm[FLOOR].pixels[e->xpm[FLOOR].w * e->rc.text_y + e->rc.text_x];
}
