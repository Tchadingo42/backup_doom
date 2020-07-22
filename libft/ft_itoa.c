/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 15:42:16 by jcanteau          #+#    #+#             */
/*   Updated: 2019/11/03 21:26:45 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	nbchar(int n)
{
	int			total;

	total = 0;
	if (n < 0)
		total++;
	else if (n == 0)
		total++;
	while (n)
	{
		n /= 10;
		total++;
	}
	return (total);
}

static char		*ft_neg(int *n, int *neg)
{
	if (*n == -2147483648)
		return (ft_strdup("-2147483648"));
	else
		*n *= -1;
	*neg = 1;
	return (NULL);
}

char			*ft_itoa(int n)
{
	char		*str;
	size_t		len;
	int			neg;

	neg = 0;
	len = nbchar(n);
	if (n < 0)
		if ((str = ft_neg(&n, &neg)) != NULL)
			return (str);
	if ((str = ft_strnew(len)) == NULL)
		return (NULL);
	while (len--)
	{
		str[len] = n % 10 + '0';
		n /= 10;
	}
	if (neg)
		str[0] = '-';
	return (str);
}
