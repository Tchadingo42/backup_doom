/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps_text_time.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhang <czhang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 13:34:25 by czhang            #+#    #+#             */
/*   Updated: 2020/07/16 14:10:13 by czhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	draw_text(t_env *doom, unsigned int pos, SDL_Surface *text)
{
	int			i;
	int			j;
	Uint32		*surfpix;

	if (text->h > H || text->w > W)
		return ;
	if (pos + text->h * W + text->w > W * H)
		return ;
	surfpix = (Uint32 *)text->pixels;
	j = -1;
	while (++j < text->h)
	{
		i = -1;
		while (++i < text->w)
			doom->screen_pixels[pos + j * W + i] = surfpix[j * text->w + i];
	}
}

void	draw_centered_text(t_env *doom, SDL_Surface *text)
{
	double	value;

	value = (W - text->w) / 2 + (H * 0.3) * W;
	draw_text(doom, (unsigned int)value, text);
}

void	ft_draw_fps(t_env *doom)
{
	char	*str_frames;

	doom->fps.time_tmp = get_time(doom);
	doom->fps.frames++;
	doom->fps.count_fps++;
	if ((doom->fps.time_tmp - doom->fps.time_fps) > 1)
	{
		if ((str_frames = ft_itoa((int)doom->fps.frames)) == NULL)
			ft_exit(doom, EXIT_FAILURE, "Error malloc in itoa (ft_draw_fps)");
		SDL_FreeSurface(doom->fps.s);
		if ((doom->fps.s = TTF_RenderText_Blended(doom->txt.font,
				str_frames, doom->txt.black)) == NULL)
		{
			ft_memdel((void **)&str_frames);
			ft_exit(doom, EXIT_FAILURE, "Error in TTF_RenderText_Blended()");
		}
		ft_memdel((void **)&str_frames);
		doom->fps.frames = 0;
		doom->fps.time_fps = get_time(doom);
	}
	if (doom->fps.s != NULL)
		draw_text(doom,
			(doom->minimap.def_y + doom->block + 1) * W, doom->fps.s);
}

double	get_time(t_env *doom)
{
	struct timespec	time;
	double			ret_value;

	clock_gettime(_POSIX_MONOTONIC_CLOCK, &time);
	ret_value = time.tv_sec - doom->time0.tv_sec;
	ret_value += (time.tv_nsec - doom->time0.tv_nsec) / 1000000000.0;
	return (ret_value);
}

void	ft_funky_textures(t_env *doom)
{
	double	time;

	if ((time = get_time(doom)) < 4.45)
		draw_centered_text(doom, doom->txt.welcome1);
	else if (5.35 < time && time < 8)
		draw_centered_text(doom, doom->txt.welcome2);
	if (doom->count_puls < MAX_PULS_FUNKY_TEXTURES &&
		doom->count_puls * doom->music_puls + 6.45 < time)
	{
		doom->wall = doom->wall == 3 ? 0 : doom->wall + 1;
		if (++doom->count_puls == 25)
			doom->wall = 3;
	}
	else if (0.35 < time && time < 1.25)
		doom->wall = 0;
	else if (1.425 < time && time < 2.4)
		doom->wall = 2;
	else if (2.4 < time && time < 3.375)
		doom->wall = 1;
	else if (3.375 < time && time < 4.35)
		doom->wall = 0;
	else if (4.35 < time && time < 5.25)
		doom->wall = 2;
	else if (5.25 < time && time < 5.9)
		doom->wall = doom->wall == 3 ? 0 : doom->wall + 1;
}
