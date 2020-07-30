/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sampling.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhang <czhang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 19:57:45 by jcanteau          #+#    #+#             */
/*   Updated: 2020/07/16 11:32:39 by czhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	ft_setup_ray_hit_location(t_thread_env *e)
{
	e->rc.test_point_x = e->cam.pos_x + e->rc.eye_x *
								e->rc.distance_towall;
	e->rc.test_point_y = e->cam.pos_y + e->rc.eye_y *
								e->rc.distance_towall;
	e->rc.test_angle = atan2(
			e->rc.test_point_y - (double)e->rc.test_y - 0.5,
			e->rc.test_point_x - (double)e->rc.test_x - 0.5);
}

void	ft_calc_sampling_x(t_thread_env *e)
{
	ft_setup_ray_hit_location(e);
	e->rc.sample_x = 0;
	if (e->rc.test_angle > -PI * 0.25 && e->rc.test_angle <= PI * 0.25)
	{
		e->rc.sample_x = e->rc.test_point_y - (double)e->rc.test_y - 1;
		e->rc.orientation = WEST;
	}
	else if (e->rc.test_angle > PI * 0.25 && e->rc.test_angle <= PI * 0.75)
	{
		e->rc.sample_x = e->rc.test_point_x - (double)e->rc.test_x;
		e->rc.orientation = NORTH;
	}
	else if (e->rc.test_angle > -PI * 0.75 && e->rc.test_angle <= -PI * 0.25)
	{
		e->rc.sample_x = e->rc.test_point_x - (double)e->rc.test_x - 1;
		e->rc.orientation = SOUTH;
	}
	else if (e->rc.test_angle > PI * 0.75 || e->rc.test_angle <= -PI * 0.75)
	{
		e->rc.sample_x = e->rc.test_point_y - (double)e->rc.test_y;
		e->rc.orientation = EAST;
	}
	e->rc.sample_x = fabs(e->rc.sample_x - (int)e->rc.sample_x);
}
