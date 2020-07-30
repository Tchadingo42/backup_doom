/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 12:51:42 by jcanteau          #+#    #+#             */
/*   Updated: 2018/11/30 13:01:44 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = NULL;
	tmp2 = NULL;
	if (alst != NULL)
	{
		tmp1 = *alst;
		while (tmp1 != NULL)
		{
			if (tmp1->content != NULL)
				(*del)(tmp1->content, tmp1->content_size);
			tmp2 = tmp1;
			tmp1 = tmp1->next;
			free(tmp2);
		}
	}
	*alst = NULL;
}
