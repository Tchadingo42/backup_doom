/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 10:36:43 by jcanteau          #+#    #+#             */
/*   Updated: 2018/11/20 17:01:23 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	lendest;
	size_t	lensrc;

	lendest = ft_strlen(dst);
	lensrc = ft_strlen((char *)src);
	if (lendest >= size)
		return (lensrc + size);
	ft_strncat(dst, src, size - lendest - 1);
	return (lendest + lensrc);
}
