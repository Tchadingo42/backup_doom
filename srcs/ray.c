/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 21:52:39 by jcanteau          #+#    #+#             */
/*   Updated: 2020/07/21 03:18:31 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	ft_setup(t_thread_env *e)
{
	e->rc.deltadistx = sqrt(1 + (e->rc.eye_y *
		e->rc.eye_y) / (e->rc.eye_x * e->rc.eye_x));
	e->rc.deltadisty = sqrt(1 + (e->rc.eye_x *
		e->rc.eye_x) / (e->rc.eye_y * e->rc.eye_y));
	e->rc.test_x = (int)e->cam.pos_x;
	e->rc.test_y = (int)e->cam.pos_y;
}

void	ft_set_direction(t_thread_env *e)
{
	if (e->rc.eye_x < 0)
	{
		e->rc.stepx = -1;
		e->rc.sidedistx = (e->cam.pos_x - e->rc.test_x) *
			e->rc.deltadistx;
	}
	else
	{
		e->rc.stepx = 1;
		e->rc.sidedistx = (e->rc.test_x + 1 - e->cam.pos_x) *
			e->rc.deltadistx;
	}
	if (e->rc.eye_y < 0)
	{
		e->rc.stepy = -1;
		e->rc.sidedisty = (e->cam.pos_y - e->rc.test_y) *
			e->rc.deltadisty;
	}
	else
	{
		e->rc.stepy = 1;
		e->rc.sidedisty = (e->rc.test_y + 1 - e->cam.pos_y) *
			e->rc.deltadisty;
	}
}

void	ft_search_last_transparent(t_thread_env *e)
{
	int		i;

	i = 0;
	while (i < e->transparent_found)
	{
		if (e->map.data[e->rc.test_y][e->rc.test_x] == GRID)
			i++;
		if (i >= e->transparent_found)
			return ;
		if (e->rc.sidedistx < e->rc.sidedisty)
		{
			e->rc.sidedistx += e->rc.deltadistx;
			e->rc.test_x += e->rc.stepx;
			e->rc.side = 0;
		}
		else
		{
			e->rc.sidedisty += e->rc.deltadisty;
			e->rc.test_y += e->rc.stepy;
			e->rc.side = 1;
		}
	}
}

void	ft_search_collision(t_thread_env *e)
{
	while (e->map.data[e->rc.test_y][e->rc.test_x] != WALL &&
			e->map.data[e->rc.test_y][e->rc.test_x] != DOOR)
	{
		if (e->map.data[e->rc.test_y][e->rc.test_x] == GRID)
			e->transparent_found++;
		if (e->rc.sidedistx < e->rc.sidedisty)
		{
			e->rc.sidedistx += e->rc.deltadistx;
			e->rc.test_x += e->rc.stepx;
			e->rc.side = 0;
		}
		else
		{
			e->rc.sidedisty += e->rc.deltadisty;
			e->rc.test_y += e->rc.stepy;
			e->rc.side = 1;
		}
	}
}

void	ft_calcul_distance_to_collision(t_thread_env *e)
{
	if (e->rc.side == 0)
	{
		e->rc.distance_towall =
			fabs((e->rc.test_x - e->cam.pos_x +
				(1 - e->rc.stepx) / 2) / e->rc.eye_x);
	}
	else
	{
		e->rc.distance_towall =
			fabs((e->rc.test_y - e->cam.pos_y +
				(1 - e->rc.stepy) / 2) / e->rc.eye_y);
	}
}

void	ft_calc_next_intersection(t_thread_env *e, char wall_type)
{
	ft_setup(e);
	ft_set_direction(e);
	if (wall_type == WALL)
		ft_search_collision(e);
	else if (wall_type == GRID)
		ft_search_last_transparent(e);
	ft_calcul_distance_to_collision(e);
}
