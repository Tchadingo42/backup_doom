/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 15:35:37 by jcanteau          #+#    #+#             */
/*   Updated: 2018/11/23 15:37:50 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int i;
	int j;

	i = 0;
	if (needle[i] == '\0')
		return ((char*)haystack);
	while ((unsigned char)haystack[i] && i < (int)len)
	{
		j = 0;
		while ((unsigned char)haystack[i] == (unsigned char)needle[j]
				&& i < (int)len)
		{
			if ((unsigned char)needle[j + 1] == '\0')
				return ((char*)&haystack[i - j]);
			i++;
			j++;
		}
		i -= j;
		i++;
	}
	return (NULL);
}
