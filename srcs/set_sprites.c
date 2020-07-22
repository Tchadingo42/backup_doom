/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sprites.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbelan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 14:16:04 by chbelan           #+#    #+#             */
/*   Updated: 2020/07/22 15:31:09 by chbelan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

static void				sprites(t_elem *elem)
{
	if (!(elem->sprite[0].img = SDL_LoadBMP("textures/sprites/gun1.bmp")))
		ft_exit("Invalid loading sprite gun1");
	if (!(elem->sprite[1].img = SDL_LoadBMP("textures/sprites/gun2.bmp")))
		ft_exit("Invalid loading sprite gun2");
	if (!(elem->sprite[2].img = SDL_LoadBMP("textures/sprites/monster.bmp")))
		ft_exit("Invalid loading sprite monster");
	if (!(elem->sprite[3].img = SDL_LoadBMP("textures/sprites/monsteratk.bmp")))
		ft_exit("Invalid loading sprite monsteratk");
	if (!(elem->sprite[4].img = SDL_LoadBMP("textures/sprites/monsterhit.bmp")))
		ft_exit("Invalid loading sprite monsterhit");
	if (!(elem->sprite[5].img = SDL_LoadBMP("textures/sprites/golem.bmp")))
		ft_exit("Invalid loading sprite golem");
	if (!(elem->sprite[6].img = SDL_LoadBMP("textures/sprites/doom.bmp")))
		ft_exit("Invalid loading sprite doom");
}

static	void			free_sprites(t_elem *elem)
{
	size_t		i;

	i = SIZE;
	while (i--)
	{
		if (elem->sprite[i].img)
			SDL_FreeSurface(elem->sprite[i].img);
	}
}

static void				ft_exit(t_env *env, t_elem *elem, char *str)
{
	if (env)
	{
		if (env->window)
			SDL_DestroyWindow(env->window);
		if (env->renderer)
			SDL_DestroyRenderer(env->renderer);
		free_sprites(elem);
		SDL_Quit();
	}
	ft_putendl(str);
	exit(EXIT_SUCCESS);
}
