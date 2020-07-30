/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmod_start_up.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 06:51:22 by jcanteau          #+#    #+#             */
/*   Updated: 2020/07/28 17:51:59 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	ft_free_fmod(t_env *doom)
{
	if ((FMOD_Sound_Release(doom->sound.jump)) != FMOD_OK)
		perror("Error in FMOD_Sound_Release of jump");
	if ((FMOD_Sound_Release(doom->sound.switch_on)) != FMOD_OK)
		perror("Error in FMOD_Sound_Release of switch_on");
	if ((FMOD_Sound_Release(doom->sound.switch_off)) != FMOD_OK)
		perror("Error in FMOD_Sound_Release of switch_off");
	if ((FMOD_Sound_Release(doom->sound.door_opening)) != FMOD_OK)
		perror("Error in FMOD_Sound_Release of door_opening");
	if ((FMOD_Sound_Release(doom->sound.door_closing)) != FMOD_OK)
		perror("Error in FMOD_Sound_Release of door_closing");
	if ((FMOD_Sound_Release(doom->sound.music)) != FMOD_OK)
		perror("Error in FMOD_Sound_Release of music");
	if ((FMOD_System_Close(doom->sound.system)) != FMOD_OK)
		perror("Error in FMOD_System_Close ");
	if ((FMOD_System_Release(doom->sound.system)) != FMOD_OK)
		perror("Error in FMOD_System_Release ");
}

void	ft_fmod(t_env *doom)
{
	if ((FMOD_System_Create(&doom->sound.system)) != FMOD_OK)
		perror("Error in FMOD_System_Create ");
	if ((FMOD_System_Init(doom->sound.system, 32, FMOD_INIT_NORMAL, NULL)) !=
			FMOD_OK)
		perror("Error in FMOD_System_Init ");
	if ((FMOD_System_CreateSound(doom->sound.system, "sounds/mario_jump.mp3",
			FMOD_CREATESAMPLE, 0, &doom->sound.jump)) != FMOD_OK)
		perror("Error in FMOD_System_CreateSound for jump ");
	if ((FMOD_System_CreateSound(doom->sound.system,
			"sounds/music/doom_music.mp3", FMOD_CREATESTREAM, 0,
				&doom->sound.music)) != FMOD_OK)
		perror("Error in FMOD_System_CreateSound for music ");
	if ((FMOD_System_CreateSound(doom->sound.system,
			"sounds/switch_on.wav", FMOD_CREATESTREAM, 0,
				&doom->sound.switch_on)) != FMOD_OK)
		perror("Error in FMOD_System_CreateSound for switch_on ");
	if ((FMOD_System_CreateSound(doom->sound.system,
			"sounds/switch_off.wav", FMOD_CREATESTREAM, 0,
				&doom->sound.switch_off)) != FMOD_OK)
		perror("Error in FMOD_System_CreateSound for switch_off ");
	if ((FMOD_System_CreateSound(doom->sound.system,
			"sounds/laser_shot.wav", FMOD_CREATESTREAM, 0,
				&doom->sound.laser_shot)) != FMOD_OK)
		perror("Error in FMOD_System_CreateSound for laser_shot ");
	if ((FMOD_System_CreateSound(doom->sound.system,
                        "sounds/shotgun.wav", FMOD_CREATESTREAM, 0,
                                &doom->sound.shotgun)) != FMOD_OK)
                perror("Error in FMOD_System_CreateSound for shotgun ");
	if ((FMOD_System_CreateSound(doom->sound.system,
			"sounds/door_opening.wav", FMOD_CREATESTREAM, 0,
				&doom->sound.door_opening)) != FMOD_OK)
		perror("Error in FMOD_System_CreateSound for door_opening ");
	if ((FMOD_System_CreateSound(doom->sound.system,
			"sounds/door_closing.wav", FMOD_CREATESTREAM, 0,
				&doom->sound.door_closing)) != FMOD_OK)
		perror("Error in FMOD_System_CreateSound for door_closing ");
	if ((FMOD_Sound_SetLoopCount(doom->sound.music, -1)) != FMOD_OK)
		perror("Error in FMOD_Sound_SetLoopCount for music ");
}
