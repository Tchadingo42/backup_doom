/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_start_up.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:10:29 by jcanteau          #+#    #+#             */
/*   Updated: 2020/07/22 13:43:04 by chbelan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	ft_exit(t_env *doom, int exit_type, char *message)
{
	struct timespec start;

	doom->multithread.stop = 1;
	ft_destroy_texture_renderer_window(doom);
	ft_memdel((void **)&doom->screen_pixels);
	Mix_FreeMusic(doom->music);
	TTF_CloseFont(doom->txt.font);
	SDL_FreeSurface(doom->txt.welcome1);
	SDL_FreeSurface(doom->txt.welcome2);
	SDL_FreeSurface(doom->fps.s);
	TTF_Quit();
	ft_putendl("next step is SDL_Quit()");
	SDL_Quit();
	ft_putendl("SDL_Quit accomplished");
	ft_free_door(doom->door);
	free_xpm(doom);
	ft_free_map(&doom->map);
	free_thread_env(doom);
	if (message != NULL)
		ft_putendl_fd(message, 2);
	clock_gettime(_POSIX_MONOTONIC_CLOCK, &start);
	printf("time ~ from SDL_Init() : %f\n", get_time(doom));
	exit(exit_type);
}

void	ft_load_surface(t_env *doom, char *image_file, SDL_Surface **dest)
{
	SDL_Surface	*tmp;

	tmp = NULL;
	tmp = SDL_LoadBMP(image_file);
	if (tmp == NULL)
		ft_exit(doom, EXIT_FAILURE, "Error in SDL_LoadBMP()");
	*dest = SDL_ConvertSurfaceFormat(tmp, SDL_PIXELFORMAT_RGBA8888, 1);
	SDL_FreeSurface(tmp);
	if (*dest == NULL)
		ft_exit(doom, EXIT_FAILURE, "Error in SDL_ConvertSurfaceFormat()");
}

void	ft_init_video(t_env *doom)
{
	doom->window = SDL_CreateWindow("doom", SDL_WINDOWPOS_CENTERED,
					SDL_WINDOWPOS_CENTERED, W, H, 0);
	if (doom->window == NULL)
		ft_exit(doom, EXIT_FAILURE, "Error in SDL_CreateWindow()");
	doom->renderer = SDL_CreateRenderer(doom->window, -1,
										SDL_RENDERER_SOFTWARE);
	if (doom->renderer == NULL)
		ft_exit(doom, EXIT_FAILURE, "Error in SDL_CreateRenderer()");
	doom->texture = SDL_CreateTexture(doom->renderer, SDL_PIXELFORMAT_RGBA8888,
						SDL_TEXTUREACCESS_STREAMING, W, H);
	if (doom->texture == NULL)
		ft_exit(doom, EXIT_FAILURE, "Error in SDL_CreateTexture()");
	get_xpm("textures/risitas_wall.xpm", &doom->xpm[NORTH]);
	get_xpm("textures/po.xpm", &doom->xpm[SOUTH]);
	get_xpm("textures/green_wall.xpm", &doom->xpm[WEST]);
	get_xpm("textures/doge.xpm", &doom->xpm[EAST]);
	get_xpm("textures/floor.xpm", &doom->xpm[FLOOR]);
	get_xpm("textures/sky2.xpm", &doom->xpm[SKY]);
	get_xpm("textures/grid2.xpm", &doom->xpm[GRID_XPM]);
	get_xpm("textures/crosshair.xpm", &doom->xpm[CROSSHAIR]);
}

void	ft_init_musicttf(t_env *doom)
{
	if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 1024) < 0)
		ft_exit(doom, EXIT_FAILURE, "Error in Mix_OpenAudio");
	if ((doom->music = Mix_LoadMUS("yaeji-raingurl.mp3")) == NULL)
		ft_exit(doom, EXIT_FAILURE, (char *)SDL_GetError());
	Mix_PlayMusic(doom->music, -1);
	Mix_VolumeMusic(0);
	if (TTF_Init() < 0)
		ft_exit(doom, EXIT_FAILURE, "Error in TTF_Init()");
	if ((doom->txt.font = TTF_OpenFont("arial.ttf", 40)) == NULL)
		ft_exit(doom, EXIT_FAILURE, "Error in TTF_OpenFont()");
	if (!(doom->txt.welcome1 = TTF_RenderText_Blended(doom->txt.font,
				" Hello stranger ! Welcome to... ", doom->txt.black)))
		ft_exit(doom, EXIT_FAILURE, "Error in TTF_RenderText_Blended()");
	if (!(doom->txt.welcome2 = TTF_RenderText_Blended(doom->txt.font,
				" The funkiest Doom Nukem ! ", doom->txt.black)))
		ft_exit(doom, EXIT_FAILURE, "Error in TTF_RenderText_Blended()");
}

void	ft_sdl(t_env *doom)
{
	if ((SDL_Init(SDL_INIT_VIDEO)) != 0)
		ft_exit(doom, EXIT_FAILURE, "Error in SDL_Init()");
	ft_init_video(doom);
	ft_init_musicttf(doom);
	clock_gettime(_POSIX_MONOTONIC_CLOCK, &doom->time0);
	while (1)
	{
		ft_print(doom);
		while (SDL_PollEvent(&doom->event))
		{
			if (doom->event.type == SDL_KEYDOWN)
				ft_key_pressed(doom);
			if (doom->event.type == SDL_KEYUP)
				ft_key_released(doom);
			if (doom->event.type == SDL_QUIT)
				ft_exit(doom, EXIT_SUCCESS, NULL);
		}
		ft_refresh_new_pos(doom);
		if (FPS_TEST && get_time(doom) > 5)
		{
			printf("moyenne fps en 5sec : %f\n", doom->fps.count_fps / 5.0);
			ft_exit(doom, 0, 0);
		}
	}
	ft_exit(doom, EXIT_SUCCESS, NULL);
}
