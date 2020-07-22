/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 18:22:00 by jcanteau          #+#    #+#             */
/*   Updated: 2018/11/13 16:46:50 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	int i;
	int j;

	i = 0;
	if (to_find[i] == 0)
		return ((char *)str);
	while (str[i])
	{
		j = 0;
		while (str[i] == to_find[j])
		{
			if (to_find[j + 1] == '\0')
				return ((char *)&str[i - j]);
			i++;
			j++;
		}
		i -= j;
		i++;
	}
	return (0);
}
