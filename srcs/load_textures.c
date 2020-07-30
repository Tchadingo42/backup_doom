/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 01:42:21 by jcanteau          #+#    #+#             */
/*   Updated: 2020/07/30 10:07:41 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void		ft_load_wall_textures(t_env *doom)
{
	if ((get_xpm("textures/wall_skull.xpm", &doom->xpm[NORTH])) != 0)
		ft_exit(doom, EXIT_FAILURE,"Error in get_xpm() for wall_skull.xpm");
	if ((get_xpm("textures/wall_skull.xpm", &doom->xpm[SOUTH])) != 0)
		ft_exit(doom, EXIT_FAILURE,"Error in get_xpm() for wall_skull.xpm");
	if ((get_xpm("textures/wall_skull.xpm", &doom->xpm[WEST])) != 0)
		ft_exit(doom, EXIT_FAILURE,"Error in get_xpm() for wall_skull.xpm");
	if ((get_xpm("textures/wall_skull.xpm", &doom->xpm[EAST])) != 0)
		ft_exit(doom, EXIT_FAILURE,"Error in get_xpm() for wall_skull.xpm");
}

void		ft_load_floor_sky_textures(t_env *doom)
{
	if ((get_xpm("textures/floor_metal.xpm", &doom->xpm[FLOOR])) != 0)
		ft_exit(doom, EXIT_FAILURE,"Error in get_xpm() for floor_metal.xpm");
	if ((get_xpm("textures/sky_red.xpm", &doom->xpm[SKY])) != 0)
		ft_exit(doom, EXIT_FAILURE,"Error in get_xpm() for sky_red.xpm");
}

void		ft_load_torch_textures(t_env *doom)
{
	if ((get_xpm("textures/torch/torch_1.xpm", &doom->xpm[TORCH_1_XPM])) != 0)
		ft_exit(doom, EXIT_FAILURE,"Error in get_xpm() for torch_1.xpm");
	if ((get_xpm("textures/torch/torch_2.xpm", &doom->xpm[TORCH_2_XPM])) != 0)
		ft_exit(doom, EXIT_FAILURE,"Error in get_xpm() for torch_2.xpm");
	if ((get_xpm("textures/torch/torch_3.xpm", &doom->xpm[TORCH_3_XPM])) != 0)
		ft_exit(doom, EXIT_FAILURE,"Error in get_xpm() for torch_3.xpm");
	if ((get_xpm("textures/torch/torch_4.xpm", &doom->xpm[TORCH_4_XPM])) != 0)
		ft_exit(doom, EXIT_FAILURE,"Error in get_xpm() for torch_4.xpm");
	if ((get_xpm("textures/torch/torch_5.xpm", &doom->xpm[TORCH_5_XPM])) != 0)
		ft_exit(doom, EXIT_FAILURE,"Error in get_xpm() for torch_5.xpm");
	if ((get_xpm("textures/torch/torch_6.xpm", &doom->xpm[TORCH_6_XPM])) != 0)
		ft_exit(doom, EXIT_FAILURE,"Error in get_xpm() for torch_6.xpm");
	if ((get_xpm("textures/torch/torch_7.xpm", &doom->xpm[TORCH_7_XPM])) != 0)
		ft_exit(doom, EXIT_FAILURE,"Error in get_xpm() for torch_7.xpm");
	if ((get_xpm("textures/torch/torch_8.xpm", &doom->xpm[TORCH_8_XPM])) != 0)
		ft_exit(doom, EXIT_FAILURE,"Error in get_xpm() for torch_8.xpm");
}

void		ft_load_textures(t_env *doom)
{
	ft_load_wall_textures(doom);
	ft_load_floor_sky_textures(doom);
	ft_load_torch_textures(doom);
	if ((get_xpm("textures/chain.xpm", &doom->xpm[GRID_XPM])) != 0)
		ft_exit(doom, EXIT_FAILURE,"Error in get_xpm() for chain.xpm");
	if ((get_xpm("textures/crosshair.xpm", &doom->xpm[CROSSHAIR])) != 0)
		ft_exit(doom, EXIT_FAILURE,"Error in get_xpm() for crosshair.xpm");
	if ((get_xpm("textures/barrel.xpm", &doom->xpm[BARREL_XPM])) != 0)
		ft_exit(doom, EXIT_FAILURE,"Error in get_xpm() for barrel.xpm");
	if ((get_xpm("textures/button_off.xpm", &doom->xpm[BUTTON_OFF_XPM])) != 0)
		ft_exit(doom, EXIT_FAILURE,"Error in get_xpm() for button_off.xpm");
	if ((get_xpm("textures/button_on.xpm", &doom->xpm[BUTTON_ON_XPM])) != 0)
		ft_exit(doom, EXIT_FAILURE,"Error in get_xpm() for button_on.xpm");
	if ((get_xpm("textures/door_metal.xpm", &doom->xpm[DOOR_METAL_XPM])) != 0)
		ft_exit(doom, EXIT_FAILURE,"Error in get_xpm() for door_metal.xpm");
	if ((get_xpm("textures/health_potion.xpm", &doom->xpm[HEALTH_POTION_XPM])) != 0)
		ft_exit(doom, EXIT_FAILURE,"Error in get_xpm() for health_potion.xpm");
	if ((get_xpm("textures/key.xpm", &doom->xpm[KEY_XPM])) != 0)
		ft_exit(doom, EXIT_FAILURE,"Error in get_xpm() for key.xpm");
}