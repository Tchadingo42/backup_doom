/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhang <czhang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 11:57:29 by jcanteau          #+#    #+#             */
/*   Updated: 2020/07/16 14:41:35 by czhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	ft_doom(char *mapfile)
{
	t_env	doom;

	ft_initialize(&doom, mapfile);
	save_in_file(&doom);
	ft_sdl(&doom);
}
