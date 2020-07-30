/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 17:11:24 by jcanteau          #+#    #+#             */
/*   Updated: 2019/10/04 14:35:34 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include <stdio.h>
# define NO_NL -1
# define DONE 0
# define NOT_DONE 1
# define NOT_INIT -1

typedef struct	s_read
{
	char			*str;
	struct s_read	*next;
	ssize_t			nl;
	int				state;
	int				fd;
}				t_read;

int				get_next_line(const int fd, char **line);

#endif
