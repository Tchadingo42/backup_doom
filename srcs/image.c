/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 16:04:06 by jcanteau          #+#    #+#             */
/*   Updated: 2020/07/22 15:23:39 by chbelan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	ft_update_screen(t_env *doom)
{
	SDL_RenderCopy(doom->renderer, doom->texture, NULL, NULL);
	ft_set_sdl_minimap_colors(doom);
	SDL_RenderPresent(doom->renderer);
}

void	ft_print(t_env *doom)
{
	doom->new_values++;
	pthread_cond_signal(&doom->multithread.cond);
	animation_opening_door(doom);
	//ft_raycaster(doom);
	import_screenpixels(doom);
	ft_draw_minimap(doom);
	ft_draw_fps(doom);
	ft_draw_crosshair(doom);
	if (!doom->no_funky)
		ft_funky_textures(doom);
	ft_update_screen(doom);
	if ((SDL_UpdateTexture(doom->texture, NULL,
					doom->screen_pixels,
					doom->pitch)) < 0)
		ft_exit(doom, EXIT_FAILURE, "Error in SDL_UpdateTexture()");
}
