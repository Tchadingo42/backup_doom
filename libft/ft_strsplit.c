/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:32:36 by jcanteau          #+#    #+#             */
/*   Updated: 2019/10/20 15:56:39 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_word_len(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] && str[len] != ' ')
		len++;
	return (len);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	size_t	nb_word;
	size_t	len;
	int		i;

	if (s == NULL)
		return (NULL);
	i = 0;
	nb_word = ft_split_count(s, ' ');
	if ((tab = (char **)malloc(sizeof(char *) * (nb_word + 1))) == NULL)
		return (NULL);
	while (nb_word--)
	{
		if (*s == '\0')
			return (NULL);
		while (*s && *s == c)
			s++;
		len = ft_word_len(s);
		if ((tab[i] = ft_strsub(s, 0, len)) == NULL)
			return (NULL);
		s += len;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
