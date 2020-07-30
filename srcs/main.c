/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhang <czhang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 14:53:23 by jcanteau          #+#    #+#             */
/*   Updated: 2020/07/26 22:05:06 by czhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

int		ft_usage(void)
{
	ft_putendl_fd("usage: ./doom [file.map]", 2);
	return (EXIT_FAILURE);
}

int		ft_random(void)
{
	ft_putendl_fd("/dev/random cannot be used", 2);
	return (EXIT_FAILURE);
}

int		main(int ac, char **av)
{
	if (ac != 2 && ac != 3)
		return (ft_usage());
	if (ft_strcmp("/dev/random", av[1]) == 0)
		return (ft_random());
	if (ac == 2)
		ft_doom(av[1]);
	else if (ac == 3)
		editor(av[1]);
	return (0);
}

/*
**  int		main(int ac, char **av)
**  {
**  	SDL_Window		*test_window;
**  	SDL_Renderer	*test_renderer;
**  	SDL_Texture		*test_texture;
**
**  	(void)ac;
**  	(void)av;
**  	SDL_Init(SDL_INIT_VIDEO);
**  	test_window = SDL_CreateWindow("doom",
**  					SDL_WINDOWPOS_CENTERED,
**  					SDL_WINDOWPOS_CENTERED,
**  					W,
**  					H,
**  					0);
**  	if (test_window == NULL)
**  		exit(EXIT_FAILURE);
**  	test_renderer = SDL_CreateRenderer(test_window,
**  										-1,
**  										SDL_RENDERER_ACCELERATED);
**  	if (test_renderer == NULL)
**  		exit(EXIT_FAILURE);
**  	test_texture = SDL_CreateTexture(test_renderer,
**  									SDL_PIXELFORMAT_RGBA8888,
**  									SDL_TEXTUREACCESS_STREAMING,
**  									W,
**  									H);
**  	if (test_texture == NULL)
**  		exit(EXIT_FAILURE);
** 	SDL_RenderCopy(test_renderer, test_texture, NULL, NULL);
**  	if (test_texture != NULL)
**  	{
**  		SDL_DestroyTexture(test_texture);
**  		test_texture = NULL;
**  	}
**  	if (test_renderer != NULL)
**  	{
**  		SDL_DestroyRenderer(test_renderer);
**  		test_renderer = NULL;
**  	}
**  	if (test_window != NULL)
**  	{
**  		SDL_DestroyWindow(test_window);
**  		test_window = NULL;
**  	}
**  	SDL_Quit();
**  	return (0);
**  }
*/
