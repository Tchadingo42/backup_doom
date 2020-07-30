/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 13:03:25 by vduvinag          #+#    #+#             */
/*   Updated: 2020/07/30 09:50:56 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

int		ft_check_borders(t_map *map)
{
	int		i;
	char	*line;

	line = map->data + map->cur_line * map->nbcol;
	i = 0;
	while (i < map->nbcol)
	{
		if (line[i] != '#')
			return (-1);
		i++;
	}
	return (0);
}

int		ft_check_line(t_map *m)
{
	int		i;
	char	*l;

	l = m->data + m->cur_line * m->nbcol;
	i = 0;
	if (l[i++] != '#')
		return (-2);
	while (i < m->nbcol)
	{
		if (l[i] != EMPTY && l[i] != WALL && l[i] != DOOR && l[i] != OBJECT &&
				l[i] != TORCH && l[i] != GRID && l[i] != BARREL &&
				l[i] != BUTTON_OFF && l[i] != BUTTON_ON && l[i] != DOOR_OPENED &&
				l[i] != HEALTH_POTION && l[i] != KEY)
			return (-1);
		i++;
	}
	if (l[--i] != '#')
		return (-2);
	i = -1;
	while (++i < m->nbcol)
		if (m->bright[m->cur_line * m->nbcol + i] < 0
				|| m->bright[m->cur_line * m->nbcol + i] > 3)
			return (-3);
	return (0);
}

int		precheck_one(char *l, int p)
{
	int		i;

	i = 0;
	if (l[p + i] != WALL && l[p + i] != EMPTY && l[p + i] != DOOR &&
			l[p + i] != TORCH && l[p + i] != OBJECT && l[p + i] != GRID &&
			l[p + i] != BARREL && l[p + i] != BUTTON_OFF &&
			l[p + i] != BUTTON_ON && l[p + i] != DOOR_OPENED &&
			l[p + i] != HEALTH_POTION && l[p + i] != KEY)
		return (-1);
	i++;
	if (l[p + i] != ' ')
		return (-2);
	i++;
	if (!ft_isdigit(l[p + i]) || ft_atoi(l + p + i) < 0)
		return (-3);
	while (ft_isdigit(l[p + i]))
		i++;
	if (l[p + i++] != ' ')
		return (-2);
	if (!ft_isdigit(l[p + i]) || ft_atoi(l + p + i) < 0)
		return (-3);
	while (ft_isdigit(l[p + i]))
		i++;
	if (l[p + i] == '\0')
		return (0);
	else if (l[p + i] != '\t')
		return (-2);
	i++;
	return (i);
}

int		precheck_line(char *line)
{
	size_t	nbcol;
	int		pos;
	int		pos_one;

	nbcol = 1;
	pos = 0;
	while (nbcol < 100 && (pos_one = precheck_one(line, pos)) > 0)
	{
		nbcol++;
		pos += pos_one;
	}
	if (pos_one == 0)
		return (nbcol);
	return (-1);
}

void	ft_count_lines_columns(t_map *m, char *mapfile, int fd)
{
	char	*line;

	if ((fd = open(mapfile, O_RDONLY)) < 0)
		ft_norme(5);
	line = NULL;
	if ((get_next_line(fd, &line)) <= 0)
		ft_error(m, 6, line);
	if ((m->nbcol = precheck_line(line)) == -1)
		ft_error(m, 3, line);
	ft_memdel((void **)&line);
	m->nbl++;
	while (get_next_line(fd, &line) > 0)
	{
		if (m->nbcol != precheck_line(line))
		{
			close(fd);
			ft_error(m, 2, line);
		}
		m->nbl++;
		ft_memdel((void **)&line);
	}
	if (close(fd) < 0)
		ft_error(m, 7, line);
}

void	ft_error(t_map *m, int code, char *line)
{
	if (code == 1)
		ft_putendl_fd("error during malloc of map", 2);
	if (code == 2)
		ft_putendl_fd("Please use a rectangle map", 2);
	if (code == 3)
		ft_putendl_fd("map format is invalid", 2);
	if (code == 4)
		ft_putendl_fd("Your map is missing borders, BUILD THAT WALL", 2);
	if (code == 5)
		ft_putendl_fd("Error during open()", 2);
	if (code == 6)
		ft_putendl_fd("map is empty", 2);
	if (code == 7)
		ft_putendl_fd("Error during close()", 2);
	if (code == 8)
		ft_putendl_fd("Map is too big", 2);
	ft_memdel((void **)&line);
	ft_free_map(m);
	exit(EXIT_FAILURE);
}

void	ft_norme(int code)
{
	if (code == 5)
		ft_putendl_fd("Error during open() ", 2);
	exit(EXIT_FAILURE);
}
