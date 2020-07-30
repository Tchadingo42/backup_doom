/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 16:18:39 by jcanteau          #+#    #+#             */
/*   Updated: 2019/08/03 14:57:43 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c,
		size_t n)
{
	size_t			i;
	unsigned char	*temp;

	temp = (unsigned char *)src;
	i = -1;
	while (++i < n)
	{
		ft_memcpy(dst + i, &temp[i], 1);
		if (temp[i] == (unsigned char)c)
			return (dst + i + 1);
	}
	return (NULL);
}
