/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 14:31:10 by jcanteau          #+#    #+#             */
/*   Updated: 2018/11/30 17:27:22 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *dsttmp;
	unsigned char *srctmp;

	srctmp = (unsigned char*)src;
	dsttmp = (unsigned char*)dst;
	if (len > 0)
	{
		if (src >= dst)
			ft_memcpy(dst, src, len);
		else
		{
			while (--len > 0)
				dsttmp[len] = srctmp[len];
			dsttmp[0] = srctmp[0];
		}
	}
	return (dst);
}
