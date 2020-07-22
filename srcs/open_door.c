/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_door.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhang <czhang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 04:49:08 by czhang            #+#    #+#             */
/*   Updated: 2020/07/16 14:41:20 by czhang           ###   ########.fr       */
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
		doom->map.alt[d->y][d->x] = d->start_alt + duration * d->speed;
	}
	else if (duration >= DOOR_OPENING_DURATION)
	{
		doom->map.data[door->y][door->x] = '.';
		doom->map.alt[door->y][door->x] = 1;
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
		if (doom->map.data[door->y][door->x] == '.')
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
	if (!last)
		printf("ya r\n");
	if (last == NULL)
		doom->door = d;
	else if (last)
		last->next = d;
	d->start_time = get_time(doom);
	d->start_alt = doom->map.alt[door_y][door_x];
	d->speed = (MIN_ALTITUDE - d->start_alt) / (double)DOOR_OPENING_DURATION;
	d->x = door_x;
	d->y = door_y;
}

static void	init_door(t_env *doom, int door_y, int door_x)
{
	t_door	*last;

	last = doom->door;
	while (last && last->next)
		last = last->next;
	new_door(doom, door_y, door_x, last);
}

void		resolve_door(t_env *doom)
{
	int		y;
	int		x;
	double	angle;
	char	**d;

	d = doom->map.data;
	y = (int)doom->cam.pos_y;
	x = (int)doom->cam.pos_x;
	angle = doom->cam.angle;
	if ((angle <= -PI * 0.25 && angle >= -PI * 0.75) && d[y][x - 1] == 'D')
		x = x - 1;
	else if ((angle >= PI * 0.75 || angle <= -PI * 0.75) && d[y - 1][x] == 'D')
		y = y - 1;
	else if ((angle >= -PI * 0.25 && angle <= PI * 0.25) && d[y + 1][x] == 'D')
		y = y + 1;
	else if ((angle >= PI * 0.25 && angle <= PI * 0.75) && d[y][x + 1] == 'D')
		x = x + 1;
	else
		return ;
	init_door(doom, y, x);
}
