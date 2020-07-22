/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pthread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhang <czhang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 23:27:33 by czhang            #+#    #+#             */
/*   Updated: 2020/07/16 14:54:19 by czhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	import_screenpixels(t_env *doom)
{
	int				i;
	int				x;
	int				y;
	t_multithread	*pt;
	Uint32			*scr_p;

	pt = (t_multithread*)&doom->multithread;
	scr_p = (Uint32*)doom->screen_pixels;
	i = -1;
	pthread_mutex_lock(&pt->mutex);
	while (++i < pt->max)
	{
		x = pt->tab[i].x_start - 1;
		while (++x < pt->tab[i].x_end)
		{
			y = -1;
			while (++y < H)
				scr_p[y * W + x] = pt->tab[i].screen_pixels[y * W + x];
		}
	}
	pthread_mutex_unlock(&pt->mutex);
}

void	*routine(void *arg)
{
	t_thread_env	*e;
	t_env			*doom;
	t_multithread	*multithread;

	e = (t_thread_env *)arg;
	doom = (t_env *)e->doom;
	multithread = (t_multithread *)e->multithread;
	while (!multithread->stop)
	{
		pthread_mutex_lock(e->mutex);
		while (!doom->new_values)
			pthread_cond_wait(&multithread->cond, e->mutex);
		e->cam = doom->cam;
		e->map = doom->map;
		e->wall = doom->wall;
		pthread_mutex_unlock(e->mutex);
		ft_raycaster(e);
	}
	return (0);
}

void	init_thread_env(t_env *doom, int i)
{
	t_thread_env	*e;
	t_multithread	*multithread;

	multithread = &doom->multithread;
	e = &multithread->tab[i];
	e->screen_pixels = (Uint32*)ft_memalloc(sizeof(Uint32) * W * H);
	if (e->screen_pixels == NULL)
		ft_exit(doom, 0, "Error malloc e->screen_pixels");
	e->doom = doom;
	e->multithread = (t_multithread *)&doom->multithread;
	e->xpm = doom->xpm;
	e->x_start = i * W / multithread->max;
	e->x_end = (i + 1) * W / multithread->max;
	e->mutex = &multithread->mutex;
	if (pthread_create(&e->thread, NULL, routine, e) != 0)
		ft_exit(doom, 0, "Could not create thread %d\n");
}

void	init_pthread(t_env *doom)
{
	int				i;
	t_multithread	*multi;

	multi = &doom->multithread;
	multi->max = sysconf(_SC_NPROCESSORS_CONF);
	if (multi->max > MAX_PROCESSOR)
		multi->max = MAX_PROCESSOR;
	multi->tab = (t_thread_env*)ft_memalloc(sizeof(t_thread_env) * multi->max);
	if (multi->tab == NULL)
		ft_exit(doom, 0, "(t_thread_env *) not malloc ed");
	pthread_mutex_init(&multi->mutex, 0);
	pthread_cond_init(&multi->cond, 0);
	i = -1;
	while (++i < multi->max)
		init_thread_env(doom, i);
}
