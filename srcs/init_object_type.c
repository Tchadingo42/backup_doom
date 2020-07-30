/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_object_type.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 00:34:26 by jcanteau          #+#    #+#             */
/*   Updated: 2020/07/30 10:33:51 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void		init_draw_barrel(t_env *e, t_object *tmp)
{
	tmp->data.h_ = H / tmp->data.dist * e->cam.proj_dist / PROJ_DIST; //hauteur de l'objet a l'ecran
	tmp->data.w_ = 0.9 * H / tmp->data.dist * e->xpm[BARREL_XPM].w /
		e->xpm[BARREL_XPM].h / (e->cam.fov); // idem width
	tmp->data.y_ = (e->cam.proj_dist / tmp->data.dist) * (e->cam.pos_z) +
		e->cam.angle_z - tmp->data.h_ * 0.9; //pos depart a l'ecran
	tmp->data.x_ = W - W * tmp->data.angle / e->cam.fov - tmp->data.w_ / 2; //pos depart a l'ecran
	//tmp->delta_x_end = tmp->w_ + tmp->x_ > e->x_end ?
	//									e->x_end - tmp->x_ : tmp->w_;
	//tmp->delta_x_start = tmp->x_ < e->screen_x ? e->screen_x - tmp->x_ : 0;
	tmp->data.delta_x_end = tmp->data.w_;
	tmp->data.delta_x_start = 0;
}

void		init_draw_health_potion(t_env *e, t_object *tmp)
{
	tmp->data.h_ = 0.4 * H / tmp->data.dist * e->cam.proj_dist / PROJ_DIST;
	tmp->data.w_ = 0.4 * H / tmp->data.dist * e->xpm[HEALTH_POTION_XPM].w /
		e->xpm[HEALTH_POTION_XPM].h / e->cam.fov;
	tmp->data.y_ = (e->cam.proj_dist / tmp->data.dist) * (e->cam.pos_z) +
		e->cam.angle_z - tmp->data.h_;
	tmp->data.x_ = W - W * tmp->data.angle / e->cam.fov - tmp->data.w_ / 2;
	tmp->data.delta_x_end = tmp->data.w_;
	tmp->data.delta_x_start = 0;
}

void		init_draw_key(t_env *e, t_object *tmp)
{
	tmp->data.h_ = 0.2 * H / tmp->data.dist * e->cam.proj_dist / PROJ_DIST;
	tmp->data.w_ = 0.2 * H / tmp->data.dist * e->xpm[KEY_XPM].w /
		e->xpm[KEY_XPM].h  / e->cam.fov;
	tmp->data.y_ = (e->cam.proj_dist / tmp->data.dist) * (e->cam.pos_z) +
		e->cam.angle_z - tmp->data.h_;
	tmp->data.x_ = W - W * tmp->data.angle / e->cam.fov - tmp->data.w_ / 2;
	tmp->data.delta_x_end = tmp->data.w_;
	tmp->data.delta_x_start = 0;
}

void		init_draw_torch(t_env *e, t_object *tmp)
{
	tmp->data.h_ = 1.5 * H / tmp->data.dist * e->cam.proj_dist / PROJ_DIST;
	tmp->data.w_ = 0.15 * H / tmp->data.dist * e->xpm[KEY_XPM].w /
		e->xpm[KEY_XPM].h  / e->cam.fov;
	tmp->data.y_ = (e->cam.proj_dist / tmp->data.dist) * (e->cam.pos_z) +
		e->cam.angle_z - tmp->data.h_;
	tmp->data.x_ = W - W * tmp->data.angle / e->cam.fov - tmp->data.w_ / 2;
	tmp->data.delta_x_end = tmp->data.w_;
	tmp->data.delta_x_start = 0;
}