/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 16:42:05 by jcanteau          #+#    #+#             */
/*   Updated: 2018/11/30 11:02:30 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*temp;

	temp = (unsigned char *)s;
	i = -1;
	while (++i < n)
		if (temp[i] == (unsigned char)c)
			return ((unsigned char *)s + i);
	return (NULL);
}
