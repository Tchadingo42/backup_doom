/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhang <czhang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 00:18:51 by czhang            #+#    #+#             */
/*   Updated: 2020/07/16 14:37:40 by czhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

int		xpm_error(t_xpm *xpm, char *filename, char *message)
{
	if (message)
	{
		ft_putstr_fd(message, 2);
		ft_putstr_fd(" for ", 2);
	}
	else
		ft_putstr_fd("xpm error for ", 2);
	ft_putendl_fd(filename, 2);
	ft_putendl("");
	free_one_xpm(xpm);
	return (-1);
}

int		check_init(t_xpm *xpm, char *line, int num)
{
	if (num == 4 && (xpm->nchar = ft_strlen(line) - 13) < 1)
		return (-1);
	else if (num == xpm->colormax + 4 && *line != '/')
	{
		if (xpm->nchar != (int)ft_strlen(line) - 13)
			return (-1);
		xpm->colormax++;
	}
	else if (num == xpm->colormax + 5
					&& (xpm->w = ((int)ft_strlen(line) - 3) / xpm->nchar) < 1)
		return (-1);
	else if (num == xpm->colormax + xpm->h + 5 && *line != '}')
	{
		if (xpm->w != ((int)ft_strlen(line) - 3) / xpm->nchar
							&& line[xpm->w * xpm->nchar + 1] != '"')
			return (-1);
		xpm->h++;
	}
	return (0);
}

int		each_line(t_xpm *xpm, int fd, int (*f)(t_xpm *x, char *l, int n))
{
	char	*line;
	int		num_line;

	lseek(fd, 0, SEEK_SET);
	num_line = 0;
	line = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		if (f(xpm, line, num_line++) < 0)
		{
			return (-1);
		}
		ft_memdel((void **)&line);
	}
	return (0);
}

int		init_malloc(t_xpm *xpm)
{
	int	i;

	xpm->color = (char **)ft_memalloc(sizeof(char *) * xpm->colormax + 1);
	if (xpm->color == NULL)
		return (-1);
	i = -1;
	while (++i < xpm->colormax)
	{
		xpm->color[i] = (char *)ft_memalloc(sizeof(char) * (9 + xpm->nchar));
		if (xpm->color[i] == NULL)
			return (-1);
		xpm->color[i][xpm->nchar + 8] = '\0';
	}
	if (!(xpm->pixels = (Uint32 *)ft_memalloc(sizeof(int) * xpm->h * xpm->w)))
		return (-1);
	if (xpm->h < 1 || xpm->w < 1 || xpm->colormax < 1 || xpm->nchar < 1)
		return (-1);
	return (0);
}

int		get_xpm(char *filename, t_xpm *xpm)
{
	int		fd;

	if ((fd = open(filename, O_RDONLY)) < 0)
		return (xpm_error(xpm, filename, "Error open xpm"));
	xpm->colormax = 1;
	xpm->w = 1;
	xpm->h = 1;
	if (each_line(xpm, fd, check_init) < 0
				|| init_malloc(xpm) < 0
				|| each_line(xpm, fd, xpm_fill) < 0
				|| close(fd) < 0)
		return (xpm_error(xpm, filename, "Please only use XPM3 format"));
	fd = -1;
	while (++fd < xpm->colormax && xpm->color[fd])
		ft_memdel((void **)&xpm->color[fd]);
	ft_memdel((void **)&xpm->color);
	return (0);
}
