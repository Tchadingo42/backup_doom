# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/30 13:08:57 by jcanteau          #+#    #+#              #
#    Updated: 2020/06/25 18:09:51 by jcanteau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS +=	ft_memset.c
SRCS +=	ft_bzero.c
SRCS +=	ft_memcpy.c
SRCS +=	ft_memccpy.c
SRCS +=	ft_memmove.c
SRCS +=	ft_memchr.c
SRCS +=	ft_memcmp.c
SRCS +=	ft_strlen.c
SRCS +=	ft_strdup.c
SRCS +=	ft_strcpy.c
SRCS +=	ft_strncpy.c
SRCS +=	ft_strcat.c
SRCS +=	ft_strncat.c
SRCS +=	ft_strlcat.c
SRCS +=	ft_strchr.c
SRCS +=	ft_strrchr.c
SRCS +=	ft_strstr.c
SRCS +=	ft_strnstr.c
SRCS +=	ft_strcmp.c
SRCS +=	ft_strncmp.c
SRCS +=	ft_atoi.c
SRCS +=	ft_isalpha.c
SRCS +=	ft_isdigit.c
SRCS +=	ft_isalnum.c
SRCS +=	ft_isascii.c
SRCS +=	ft_isprint.c
SRCS +=	ft_toupper.c
SRCS +=	ft_tolower.c
SRCS +=	ft_memalloc.c
SRCS +=	ft_memdel.c
SRCS +=	ft_strnew.c
SRCS +=	ft_strdel.c
SRCS +=	ft_strclr.c
SRCS +=	ft_striter.c
SRCS +=	ft_striteri.c
SRCS +=	ft_strmap.c
SRCS +=	ft_strmapi.c
SRCS +=	ft_strequ.c
SRCS +=	ft_strnequ.c
SRCS +=	ft_strsub.c
SRCS +=	ft_strjoin.c
SRCS +=	ft_strtrim.c
SRCS +=	ft_strsplit.c
SRCS +=	ft_itoa.c
SRCS +=	ft_putchar.c
SRCS +=	ft_putstr.c
SRCS +=	ft_putendl.c
SRCS +=	ft_putnbr.c
SRCS +=	ft_putchar_fd.c
SRCS +=	ft_putstr_fd.c
SRCS +=	ft_putendl_fd.c
SRCS +=	ft_putnbr_fd.c
SRCS +=	ft_lstnew.c
SRCS +=	ft_lstdelone.c
SRCS +=	ft_lstdel.c
SRCS +=	ft_lstadd.c
SRCS +=	ft_lstiter.c
SRCS +=	ft_lstmap.c
SRCS += get_next_line.c
SRCS += ft_split_count.c
SRCS += ft_tab2d_new.c
SRCS += ft_abs.c
SRCS += ft_sign.c
SRCS += ft_rgba_to_uint32.c

OBJ = $(SRCS:.c=.o)

CFLAG = -Wall -Wextra -Werror
DEBUG = -fsanitize=address,undefined -g3

CC = gcc

HEAD += libft.h
HEAD += get_next_line.h

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)
	echo "\033[32m$(NAME) is ready \033[0m"

$(OBJ): %.o: %.c $(HEAD)
	$(CC) $(CFLAG) -c $< -o $@

clean:
	$(RM) $(OBJ)
	echo "\033[32mOBJS files of $(NAME) deleted \033[0m"

fclean: clean
	$(RM) $(NAME)
	echo "\033[32m$(NAME) deteled \033[0m"

re: fclean all

.PHONY: clean fclean re all
.SILENT:
