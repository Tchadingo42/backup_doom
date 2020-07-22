/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_in_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhang <czhang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 00:42:18 by czhang            #+#    #+#             */
/*   Updated: 2020/07/22 14:00:58 by chbelan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

size_t	pseudo_log10(int n)
{
	size_t	log;

	log = 0;
	if (n < 0)
		log++;
	while (n / 10 != 0)
	{
		log++;
		n /= 10;
	}
	return (log);
}

size_t	get_filesize(t_map *map)
{
	size_t		n;
	int			y;
	int			x;

	n = map->nbcol * map->nbl * 6 - 1;
	y = -1;
	while (++y < map->nbl)
	{
		x = -1;
		while (++x < map->nbcol)
		{
			n += pseudo_log10(map->bright[y][x]);
			n += pseudo_log10(map->alt[y][x]);
		}
	}
	return (n);
}

void	pseudo_itoa(char *str0, int n, size_t *i)
{
	char	*str;
	int		len;

	str = str0 + *i;
	len = 1 + pseudo_log10(n);
	*i += len;
	if (n < 0)
		str[0] = '-';
	while (len--)
	{
		str[len] = n % 10 + '0';
		n /= 10;
	}
}

void	fill_str(t_map *map, char *str)
{
	int		y;
	int		x;
	size_t	i;

	i = 0;
	y = -1;
	while (++y < map->nbl)
	{
		x = -1;
		while (++x < map->nbcol)
		{
			str[i++] = map->data[y][x];
			str[i++] = ' ';
			pseudo_itoa(str, map->bright[y][x], &i);
			str[i++] = ' ';
			pseudo_itoa(str, map->alt[y][x], &i);
			if (x < map->nbcol - 1)
				str[i++] = '\t';
			else if (x == map->nbcol - 1)
			{
				if (y < map->nbcol - 1)
					str[i++] = '\n';
				else if (y == map->nbcol - 1)
					str[i] = '\0';
			}
		}
	}
}

void	save_in_file(t_env *doom)
{
	int		fd;
	char	*str;
	size_t	file_size;

	if ((fd = open("testsave", O_RDWR | O_CREAT, 0664)) < 0)
		ft_exit(doom, EXIT_FAILURE, "Error open in save_in_file()");
	file_size = get_filesize(&doom->map);
	if ((str = (char *)ft_memalloc((file_size + 1) * sizeof(char))) == NULL)
		ft_exit(doom, EXIT_FAILURE, "Error malloc in save_in_file()");
	fill_str(&doom->map, str);
	if (write(fd, str, file_size) != (int)file_size)
		ft_exit(doom, EXIT_FAILURE, "Error write in save_in_file()");
	ft_memdel((void **)&str);
	if (close(fd) < 0)
		ft_exit(doom, EXIT_FAILURE, "Error close in save_in_file()");
}
