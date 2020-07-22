/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhang <czhang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 14:34:43 by czhang            #+#    #+#             */
/*   Updated: 2020/07/16 14:38:21 by czhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

int		cmp_file_info(t_xpm *xpm, char *info)
{
	int i;

	if (ft_atoi(info + 1) != xpm->w)
		return (-1);
	i = 2;
	while (info[i] && info[i] != ' ')
		i++;
	while (info[i] == ' ')
		i++;
	if (ft_atoi(info + i) != xpm->h)
		return (-1);
	while (info[i] && info[i] != ' ')
		i++;
	while (info[i] == ' ')
		i++;
	if (ft_atoi(info + i) != xpm->colormax)
		return (-1);
	while (info[i] && info[i] != ' ')
		i++;
	while (info[i] == ' ')
		i++;
	if (ft_atoi(info + i) != xpm->nchar)
		return (-1);
	return (0);
}

int		apply_color(t_xpm *x, char *line, int num, int i)
{
	int	color;

	color = -1;
	while (++color < x->colormax)
	{
		if (!ft_strncmp(1 + line + x->nchar * i, x->color[color], x->nchar))
		{
			x->pixels[(num - x->colormax - 5) * x->w + i] =
					(Uint32)strtoul(x->color[color] + 2 + x->nchar, NULL, 16);
			x->pixels[(num - x->colormax - 5) * x->w + i] <<= 8;
			break ;
		}
		else if (color == x->colormax - 1)
			return (-1);
	}
	return (0);
}

int		xpm_fill(t_xpm *xpm, char *line, int num)
{
	int	i;

	if (num == 3)
		return (cmp_file_info(xpm, line));
	else if (3 < num && num < xpm->colormax + 4)
	{
		i = -1;
		while (++i < xpm->nchar + 1)
			xpm->color[xpm->colormax + 3 - num][i] = line[1 + i];
		i--;
		while (++i < xpm->nchar + 8)
			xpm->color[xpm->colormax + 3 - num][i] = line[i + 3];
	}
	else if (xpm->colormax + 4 < num && num < xpm->colormax + 5 + xpm->h)
	{
		i = -1;
		while (++i < xpm->w)
			if (apply_color(xpm, line, num, i) < 0)
				return (-1);
	}
	return (0);
}
