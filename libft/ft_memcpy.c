/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 14:45:21 by jcanteau          #+#    #+#             */
/*   Updated: 2018/11/23 14:27:34 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int				i;
	unsigned char	*dsttemp;
	unsigned char	*srctemp;

	dsttemp = (unsigned char *)dst;
	srctemp = (unsigned char *)src;
	i = 0;
	while (i < (int)n)
	{
		dsttemp[i] = srctemp[i];
		i++;
	}
	return (dst);
}
