/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbelan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 14:24:35 by chbelan           #+#    #+#             */
/*   Updated: 2020/07/22 15:31:40 by chbelan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITES_H
# define SPRITES_H
# define SIZE 7

typedef struct	s_sprite
{
	SDL_Surface	*img;
}				t_sprite;

typedef struct	s_elem
{
	t_sprite	sprite[SIZE];
}				t_elem;

#endif
