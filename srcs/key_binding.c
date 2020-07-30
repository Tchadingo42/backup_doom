/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_binding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 12:16:41 by jcanteau          #+#    #+#             */
/*   Updated: 2020/07/30 08:33:21 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void		ft_reset_view(t_env *doom)
{
	doom->cam.fov_ratio = FOV_RATIO;
	doom->cam.fov = PI / doom->cam.fov_ratio;
	doom->cam.proj_dist = PROJ_DIST;
	doom->cam.angle_z = H / 2;
}

void		ft_change_fov(t_env *doom)
{
	if (doom->event.key.keysym.sym == SDLK_KP_PLUS)
	{
		if (doom->cam.fov_ratio - FOV_RATIO_STEP >= 2)
			doom->cam.fov_ratio -= FOV_RATIO_STEP;
		doom->cam.fov = PI / doom->cam.fov_ratio;
	}
	else if (doom->event.key.keysym.sym == SDLK_KP_MINUS)
	{
		if (doom->cam.fov_ratio + FOV_RATIO_STEP <= 6)
			doom->cam.fov_ratio += FOV_RATIO_STEP;
		doom->cam.fov = PI / doom->cam.fov_ratio;
	}
	else if (doom->event.key.keysym.sym == SDLK_KP_9)
	{
		if (doom->cam.proj_dist / PROJ_DIST_STEP <= MAX_PROJ_DIST)
			doom->cam.proj_dist /= PROJ_DIST_STEP;
	}
	else if (doom->event.key.keysym.sym == SDLK_KP_6)
	{
		if (doom->cam.proj_dist * PROJ_DIST_STEP >= MIN_PROJ_DIST)
			doom->cam.proj_dist *= PROJ_DIST_STEP;
	}
	else if (doom->event.key.keysym.sym == SDLK_KP_5)
		ft_reset_view(doom);
}

void		ft_settings(t_env *doom)
{
	ft_change_fov(doom);
	if (doom->event.key.keysym.sym == SDLK_t)
		doom->wall = doom->wall == TEXTURED ? NON_TEXTURED : doom->wall + 1;
	else if (doom->event.key.keysym.sym == SDLK_RSHIFT)
	{
		doom->no_funky = 1;
		doom->wall = TEXTURED;
	}
}

void		ft_pause_music(t_env *doom)
{
	if ((FMOD_Channel_GetPaused(doom->sound.channel_music,
			&doom->sound.state)) != FMOD_OK)
		perror("Error in FMOD_Channel_GetPaused for music ");
	if (doom->sound.state == FALSE)
	{
		if ((FMOD_Channel_SetPaused(doom->sound.channel_music, TRUE)) !=
				FMOD_OK)
			perror("Error in FMOD_Channel_SetPaused for music ");
	}
	else
	{
		if ((FMOD_Channel_SetPaused(doom->sound.channel_music, FALSE)) !=
				FMOD_OK)
			perror("Error in FMOD_Channel_SetPaused for music ");
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
	{
		doom->moves.jumping = TRUE;
		if ((FMOD_System_PlaySound(doom->sound.system, doom->sound.jump,
				NULL, 0, NULL)) != FMOD_OK)
			perror("Error in FMOD_System_PlaySound for jump ");
	}
	else if (doom->event.key.keysym.sym == SDLK_f)
	{
		if ((FMOD_System_PlaySound(doom->sound.system, doom->sound.shotgun,
				NULL, 0, NULL)) != FMOD_OK)
			perror("Error in FMOD_System_PlaySound for shotgun ");
	}
	else if (doom->event.key.keysym.sym == SDLK_p)
		ft_pause_music(doom);
	else if (doom->event.key.keysym.sym == SDLK_RETURN)
	{
		resolve_door(doom);
		ft_switch_button(doom);
	}
}
