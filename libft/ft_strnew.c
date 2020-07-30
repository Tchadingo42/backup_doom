/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 14:03:24 by jcanteau          #+#    #+#             */
/*   Updated: 2019/09/21 16:47:16 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*new;

	if ((new = (char *)ft_memalloc(sizeof(char) * (size + 1))) != NULL)
	{
		new[size] = '\0';
		return (new);
	}
	else
		return (NULL);
}
