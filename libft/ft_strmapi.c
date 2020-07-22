/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 16:50:41 by jcanteau          #+#    #+#             */
/*   Updated: 2018/11/28 15:28:34 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*new;

	if (s && f)
	{
		i = -1;
		if ((new = (char *)malloc(sizeof(char) * (ft_strlen((char *)s) + 1)))
				== NULL)
			return (NULL);
		while (s[++i])
			new[i] = f(i, s[i]);
		new[i] = '\0';
		return (new);
	}
	return (NULL);
}
