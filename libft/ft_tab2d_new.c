/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab2d_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 18:17:44 by jcanteau          #+#    #+#             */
/*   Updated: 2019/10/18 15:06:46 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		**ft_tab2d_new(size_t columns, size_t rows)
{
	size_t		i;
	int			**tab2d;
	int			*str;

	if ((tab2d = malloc(sizeof(int *) * rows)) == NULL)
		return (NULL);
	if ((str = malloc(sizeof(int) * columns * rows)) == NULL)
		return (NULL);
	i = 0;
	while (i < columns)
	{
		tab2d[i] = &str[i * rows];
		i++;
	}
	return (tab2d);
}
