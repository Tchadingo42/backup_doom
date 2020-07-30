/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_sprites_tools.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 02:02:47 by jcanteau          #+#    #+#             */
/*   Updated: 2020/07/30 10:30:09 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

int			ft_choose_and_init_torch_sprite(t_env *e, t_object *tmp)
{
	static int	id_anim = 0;
	static int	duration = 0;

	if (tmp->data.type == TORCH)
	{
		init_draw_torch(e, tmp);
		if (duration == 4)
		{
			duration = 0;
			if (id_anim >= 7)
				id_anim = 0;
			id_anim++;
		}
		else
			duration++;
		return (TORCH_1_XPM + id_anim);
	}
	return (BARREL_XPM);
}

int			ft_choose_and_init_sprite(t_env *e, t_object *tmp)
{

	if (tmp->data.type == BARREL)
	{
		init_draw_barrel(e, tmp);
		return (BARREL_XPM);
	}
	else if (tmp->data.type == HEALTH_POTION)
	{
		init_draw_health_potion(e, tmp);
		return (HEALTH_POTION_XPM);
	}
	else if (tmp->data.type == KEY)
	{
		init_draw_key(e, tmp);
		return (KEY_XPM);
	}
	return (ft_choose_and_init_torch_sprite(e, tmp));
}
