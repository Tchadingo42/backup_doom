/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pthread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhang <czhang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 23:27:33 by czhang            #+#    #+#             */
/*   Updated: 2020/07/28 15:19:56 by czhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	wait_or_signal(t_shared_data *shared_data)
{
	int	i;

	i = 0;
	while (i < shared_data->max_thread
							&& shared_data->tab_thread_env[i].work_done)
		i++;
	if (i == shared_data->max_thread)
	{
		shared_data->all_work_done = 1;
		pthread_cond_signal(&shared_data->cond_main);
		pthread_cond_wait(&shared_data->cond_main, &shared_data->mutex);
		if (shared_data->stop)
			return ;
		i = -1;
		while (++i < shared_data->max_thread)
			shared_data->tab_thread_env[i].work_done = 0;
		i = -1;
		pthread_cond_broadcast(&shared_data->cond);
	}
	else
		pthread_cond_wait(&shared_data->cond, &shared_data->mutex);
}

void	update_thread_env(t_thread_env *thread_env)
{
	t_env	*doom;

	doom = (t_env *)thread_env->doom;
	thread_env->cam = doom->cam;
	ft_memcpy(thread_env->map.data, doom->map.data,
			sizeof(char) * (thread_env->map.nbcol * thread_env->map.nbl + 1));
	ft_memcpy(thread_env->map.bright, doom->map.bright,
			sizeof(int) * thread_env->map.nbcol * thread_env->map.nbl);
	ft_memcpy(thread_env->map.alt, doom->map.alt,
			sizeof(int) * thread_env->map.nbcol * thread_env->map.nbl);
	thread_env->wall = doom->wall;
}

void	*routine(void *arg)
{
	t_thread_env	*thread_env;
	t_shared_data	*shared_data;

	thread_env = (t_thread_env *)arg;
	shared_data = (t_shared_data *)thread_env->shared_data;
	pthread_mutex_lock(&shared_data->mutex);
	while (!shared_data->stop)
	{
		pthread_mutex_unlock(&shared_data->mutex);
		ft_raycaster(thread_env);
		pthread_mutex_lock(&shared_data->mutex);
		if (shared_data->stop)
			break ;
		thread_env->work_done++;
		wait_or_signal(shared_data);
	}
	pthread_mutex_unlock(&shared_data->mutex);
	return (0);
}

void	init_thread_env(t_env *doom, int i)
{
	t_thread_env	*new_thread_env;
	t_shared_data	*shared_data;

	shared_data = &doom->shared_data;
	new_thread_env = &shared_data->tab_thread_env[i];
	new_thread_env->screen_pixels =
						(Uint32*)ft_memalloc(sizeof(Uint32) * W * H);
	if (new_thread_env->screen_pixels == NULL)
		ft_exit(doom, 0, "Error malloc new_thread_env->screen_pixels");
	new_thread_env->doom = doom;
	new_thread_env->shared_data = (t_shared_data *)&doom->shared_data;
	new_thread_env->xpm = doom->xpm;
	new_thread_env->x_start = i * W / shared_data->max_thread;
	new_thread_env->x_end = (i + 1) * W / shared_data->max_thread;
	new_thread_env->map.nbl = doom->map.nbl;
	new_thread_env->map.nbcol = doom->map.nbcol;
	if (ft_malloc_tab(&new_thread_env->map) < 0)
		ft_exit(doom, 0, "Error malloc tab in new_thread_env->map%d\n");
	update_thread_env(new_thread_env);
	if (pthread_create(&new_thread_env->thread, NULL, routine, new_thread_env))
		ft_exit(doom, 0, "Could not create thread %d\n");
}

void	init_pthread(t_env *doom)
{
	int				i;
	t_shared_data	*shared_data;

	shared_data = &doom->shared_data;
	shared_data->max_thread = sysconf(_SC_NPROCESSORS_CONF);
	if (shared_data->max_thread > MAX_PROCESSOR)
		shared_data->max_thread = MAX_PROCESSOR;
	shared_data->tab_thread_env = (t_thread_env*)
				ft_memalloc(sizeof(t_thread_env) * shared_data->max_thread);
	if (shared_data->tab_thread_env == NULL)
		ft_exit(doom, 0, "(t_thread_env *) not malloc ed");
	i = -1;
	while (++i < shared_data->max_thread)
		init_thread_env(doom, i);
}
