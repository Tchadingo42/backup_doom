/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 12:06:48 by jcanteau          #+#    #+#             */
/*   Updated: 2018/11/20 14:15:58 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	*temp;
	int				i;

	temp = (unsigned char *)s;
	i = ft_strlen((char *)s);
	while (i >= 0)
	{
		if (temp[i] == (unsigned char)c)
			return ((char *)&temp[i]);
		i--;
	}
	return (NULL);
}
