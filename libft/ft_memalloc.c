/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 14:03:05 by jcanteau          #+#    #+#             */
/*   Updated: 2018/11/22 14:03:07 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*mem;
	size_t	i;
	char	*ini;

	i = -1;
	ini = NULL;
	mem = (void *)malloc(sizeof(void) * size);
	if (mem != NULL)
	{
		ini = (char *)mem;
		while (++i < size)
			ini[i] = 0;
		return (mem);
	}
	else
		return (NULL);
}
