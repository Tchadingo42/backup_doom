/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:41:09 by jcanteau          #+#    #+#             */
/*   Updated: 2020/07/17 10:31:18 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	ft_key_released(t_env *doom)
{
	if (doom->event.key.keysym.sym == SDLK_w)
		doom->moves.forward = FALSE;
	else if (doom->event.key.keysym.sym == SDLK_a)
		doom->moves.strafe_left = FALSE;
	else if (doom->event.key.keysym.sym == SDLK_s)
		doom->moves.backward = FALSE;
	else if (doom->event.key.keysym.sym == SDLK_d)
		doom->moves.strafe_right = FALSE;
	else if (doom->event.key.keysym.sym == SDLK_RIGHT)
		doom->moves.rotate_right = FALSE;
	else if (doom->event.key.keysym.sym == SDLK_LEFT)
		doom->moves.rotate_left = FALSE;
	else if (doom->event.key.keysym.sym == SDLK_UP)
		doom->moves.rotate_up = FALSE;
	else if (doom->event.key.keysym.sym == SDLK_DOWN)
		doom->moves.rotate_down = FALSE;
	else if (doom->event.key.keysym.sym == SDLK_LSHIFT)
		doom->moves.running = FALSE;
	else if (doom->event.key.keysym.sym == SDLK_LCTRL)
		doom->moves.crouching = FALSE;
	else if (doom->event.key.keysym.sym == SDLK_e)
		doom->moves.up = FALSE;
	else if (doom->event.key.keysym.sym == SDLK_q)
		doom->moves.down = FALSE;
}

void	ft_key_pressed(t_env *doom)
{
	if (doom->event.key.keysym.sym == SDLK_ESCAPE)
		ft_exit(doom, EXIT_SUCCESS, NULL);
	ft_movement(doom);
	ft_settings(doom);
}
