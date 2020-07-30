/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_count.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 13:09:52 by jcanteau          #+#    #+#             */
/*   Updated: 2019/10/18 15:06:26 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_split_count(char const *s, char c)
{
	int		word;
	int		count;

	word = 1;
	count = 0;
	while (*s)
	{
		if (*s != c && word == 1)
		{
			count++;
			word = 0;
		}
		else if (*s == c)
			word = 1;
		s++;
	}
	return (count);
}
