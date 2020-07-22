/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 12:24:34 by jcanteau          #+#    #+#             */
/*   Updated: 2018/11/30 12:51:32 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;

	tmp = NULL;
	if (alst != NULL)
		tmp = *alst;
	if (tmp->content != NULL)
	{
		(*del)(tmp->content, tmp->content_size);
		free(tmp);
	}
	*alst = NULL;
}
