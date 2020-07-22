/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 11:16:15 by jcanteau          #+#    #+#             */
/*   Updated: 2018/11/30 12:24:16 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;

	if ((new = (t_list *)ft_memalloc(sizeof(t_list))) == NULL)
		return (NULL);
	if (content == NULL)
	{
		new->content = NULL;
		new->content_size = 0;
	}
	else
	{
		if ((new->content = malloc(content_size)) != NULL)
		{
			ft_memcpy(new->content, content, content_size);
			new->content_size = content_size;
		}
		else
		{
			free(new);
			return (NULL);
		}
	}
	new->next = NULL;
	return (new);
}
