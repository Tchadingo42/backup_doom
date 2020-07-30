/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 15:58:26 by jcanteau          #+#    #+#             */
/*   Updated: 2019/10/07 15:51:55 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void		*ft_init_struct(t_read *p, int fd)
{
	if (p == NULL)
		if ((p = malloc(sizeof(t_read))) == NULL)
			return (NULL);
	p->fd = fd;
	p->str = NULL;
	p->nl = NO_NL;
	p->state = NOT_DONE;
	p->next = NULL;
	return (p);
}

static int		ft_check_newline(char *str)
{
	int				i;

	if (!str)
		return (NO_NL);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (NO_NL);
}

static int		ft_fill_line(t_read *d, char **line)
{
	char			*str_tmp;

	if (d->nl == NO_NL)
	{
		if (d->str[0] == '\0')
		{
			free(d->str);
			ft_init_struct(d, NOT_INIT);
			return (0);
		}
		if (((*line = ft_strdup(d->str))) == NULL)
			return (-1);
		free(d->str);
		ft_init_struct(d, NOT_INIT);
		return (1);
	}
	if ((*line = ft_strsub(d->str, 0, d->nl)) == NULL)
		return (-1);
	str_tmp = ft_strsub(d->str, d->nl + 1, ft_strlen(d->str) - d->nl - 1);
	if (str_tmp == NULL)
		return (-1);
	free(d->str);
	d->str = str_tmp;
	return (1);
}

static int		ft_retrieve_line(t_read *d, char **line)
{
	char			buff[BUFF_SIZE + 1];
	char			*str_tmp;
	int				ret;

	d->nl = ft_check_newline(d->str);
	while (d->nl == NO_NL && d->state == NOT_DONE)
	{
		if ((ret = read(d->fd, buff, BUFF_SIZE)) == -1)
			return (-1);
		if (ret < BUFF_SIZE)
			d->state = DONE;
		buff[ret] = '\0';
		if ((str_tmp = ft_strjoin(d->str, buff)) == NULL)
			return (-1);
		free(d->str);
		d->str = str_tmp;
		d->nl = ft_check_newline(d->str);
	}
	return (ft_fill_line(d, line));
}

int				get_next_line(const int fd, char **line)
{
	static t_read	data = {NULL, NULL, -1, 1, -1};
	t_read			*p;

	p = &data;
	if (fd < 0 || line == NULL || BUFF_SIZE <= 0)
		return (-1);
	while (p->fd != fd)
	{
		if (p->fd == NOT_INIT)
			p->fd = fd;
		else if (p->next == NULL)
		{
			if ((p->next = ft_init_struct(p->next, fd)) == NULL)
				return (-1);
			p = p->next;
		}
		else
			p = p->next;
	}
	if (p->state == DONE && p->str == NULL)
		return (0);
	return (ft_retrieve_line(p, line));
}
