/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 16:36:07 by jcanteau          #+#    #+#             */
/*   Updated: 2018/11/28 14:31:07 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*new;

	if (s && f)
	{
		i = -1;
		if ((new = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))) == NULL)
			return (NULL);
		while (s[++i])
			new[i] = f(s[i]);
		new[i] = '\0';
		return (new);
	}
	return (NULL);
}
