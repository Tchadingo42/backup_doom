/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 14:36:08 by jcanteau          #+#    #+#             */
/*   Updated: 2020/07/22 14:03:06 by chbelan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	free_thread_env(t_env *doom)
{
	int	i;

	i = -1;
	while (++i < doom->multithread.max)
		ft_memdel((void**)&doom->multithread.tab[i].screen_pixels);
	ft_memdel((void**)&doom->multithread.tab);
}

void	free_xpm(t_env *doom)
{
	int	xpm_id;

	xpm_id = 0;
	while (xpm_id < NB_XPM)
	{
		free_one_xpm(&doom->xpm[xpm_id]);
	xpm_id++;
	}
}

void	free_one_xpm(t_xpm *xpm)
{
	int	i_color;

	if (xpm->color)
	{
		i_color = -1;
		while (++i_color < xpm->colormax && xpm->color[i_color])
			ft_memdel((void **)&xpm->color[i_color]);
		ft_memdel((void **)&xpm->color);
	}
	ft_memdel((void **)&xpm->pixels);
}

void	ft_free_door(t_door *list)
{
	if (list == NULL)
		return ;
	if (list->next)
		ft_free_door(list->next);
	ft_memdel((void **)&list);
}

void	ft_destroy_texture_renderer_window(t_env *doom)
{
	if (doom->texture != NULL)
	{
		SDL_DestroyTexture(doom->texture);
		doom->texture = NULL;
	}
	if (doom->renderer != NULL)
	{
		SDL_DestroyRenderer(doom->renderer);
		doom->renderer = NULL;
	}
	if (doom->window != NULL)
	{
		SDL_DestroyWindow(doom->window);
		doom->window = NULL;
	}
}

void	ft_free_map(t_map *m)
{
	int i;

	i = 0;
	if (m->data)
		while (i < m->nbl && m->data[i])
			ft_memdel((void **)&m->data[i++]);
	i = 0;
	if (m->bright)
		while (i < m->nbl && m->bright[i])
			ft_memdel((void **)&m->bright[i++]);
	i = 0;
	if (m->alt)
		while (i < m->nbl && m->alt[i])
			ft_memdel((void **)&m->alt[i++]);
	ft_memdel((void **)&m->data);
	ft_memdel((void **)&m->bright);
	ft_memdel((void **)&m->alt);
}
