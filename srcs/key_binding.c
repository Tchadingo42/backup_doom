/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_binding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 12:16:41 by jcanteau          #+#    #+#             */
/*   Updated: 2020/07/17 10:51:18 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void		ft_settings(t_env *doom)
{
	if (doom->event.key.keysym.sym == SDLK_KP_PLUS)
	{
		if (doom->cam.fov_ratio - POV_RATIO_STEP >= 1)
			doom->cam.fov_ratio -= POV_RATIO_STEP;
		doom->cam.fov = PI / doom->cam.fov_ratio;
	}
	else if (doom->event.key.keysym.sym == SDLK_KP_MINUS)
	{
		if (doom->cam.fov_ratio + POV_RATIO_STEP <= 6)
			doom->cam.fov_ratio += POV_RATIO_STEP;
		doom->cam.fov = PI / doom->cam.fov_ratio;
	}
	else if (doom->event.key.keysym.sym == SDLK_t)
		doom->wall = doom->wall == TEXTURED ? NON_TEXTURED : doom->wall + 1;
	else if (doom->event.key.keysym.sym == SDLK_RSHIFT)
	{
		doom->no_funky = 1;
		doom->wall = TEXTURED;
	}
}

void		ft_movement(t_env *doom)
{
	if (doom->event.key.keysym.sym == SDLK_w)
		doom->moves.forward = TRUE;
	else if (doom->event.key.keysym.sym == SDLK_a)
		doom->moves.strafe_left = TRUE;
	else if (doom->event.key.keysym.sym == SDLK_s)
		doom->moves.backward = TRUE;
	else if (doom->event.key.keysym.sym == SDLK_d)
		doom->moves.strafe_right = TRUE;
	else if (doom->event.key.keysym.sym == SDLK_RIGHT)
		doom->moves.rotate_right = TRUE;
	else if (doom->event.key.keysym.sym == SDLK_LEFT)
		doom->moves.rotate_left = TRUE;
	else if (doom->event.key.keysym.sym == SDLK_UP)
		doom->moves.rotate_up = TRUE;
	else if (doom->event.key.keysym.sym == SDLK_DOWN)
		doom->moves.rotate_down = TRUE;
	else if (doom->event.key.keysym.sym == SDLK_LSHIFT)
		doom->moves.running = TRUE;
	else if (doom->event.key.keysym.sym == SDLK_LCTRL)
		doom->moves.crouching = TRUE;
	else if (doom->event.key.keysym.sym == SDLK_e)
		doom->moves.up = TRUE;
	else if (doom->event.key.keysym.sym == SDLK_q)
		doom->moves.down = TRUE;
	else if (doom->event.key.keysym.sym == SDLK_SPACE)
		doom->moves.jumping = TRUE;
	else if (doom->event.key.keysym.sym == SDLK_RETURN)
		resolve_door(doom);
}
