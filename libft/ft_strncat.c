/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 19:07:30 by jcanteau          #+#    #+#             */
/*   Updated: 2018/11/23 15:20:44 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t nb)
{
	size_t		i;
	size_t		j;

	i = ft_strlen(dest);
	j = 0;
	while (j < nb && src[j])
		dest[i++] = (char)src[j++];
	dest[i] = '\0';
	return (dest);
}
