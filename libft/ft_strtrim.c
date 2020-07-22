/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 17:49:59 by jcanteau          #+#    #+#             */
/*   Updated: 2018/11/28 15:24:10 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*new;
	size_t	start;
	size_t	end;

	if (!s)
		return (NULL);
	start = 0;
	end = ft_strlen((char *)s);
	if (end == 0)
		return (ft_strdup(""));
	while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
		start++;
	if (s[start] == '\0')
		return (ft_strdup(""));
	end--;
	while (s[end] == ' ' || s[end] == '\n' || s[end] == '\t' || *s == '\0')
		end--;
	if (start == 0 && end == ft_strlen((char *)s))
		return ((char *)s);
	if ((new = ft_strnew((end - start + 1) * (sizeof(char)))) == NULL)
		return (NULL);
	ft_strncpy(new, &s[start], (end - start + 1) * sizeof(char));
	return (new);
}
