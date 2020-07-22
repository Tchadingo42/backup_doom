# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/02 11:22:48 by jcanteau          #+#    #+#              #
#    Updated: 2020/07/21 03:51:32 by jcanteau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = doom

INC_NAME += doom.h
INC_NAME += colors.h
INC_NAME += defines.h

SRC_NAME += main.c
SRC_NAME += doom.c
SRC_NAME += sdl_start_up.c
SRC_NAME += key_hook.c
SRC_NAME += image.c
SRC_NAME += init.c
SRC_NAME += init_map.c
SRC_NAME += key_binding.c
SRC_NAME += refresh_pos.c
SRC_NAME += map_checker.c
SRC_NAME += raycaster.c
SRC_NAME += raycaster_tools.c
SRC_NAME += sampling.c
SRC_NAME += minimap.c
SRC_NAME += switch_textures.c
SRC_NAME += freeing.c
SRC_NAME += open_door.c
SRC_NAME += ray.c
SRC_NAME += save_in_file.c
SRC_NAME += xpm.c
SRC_NAME += xpm2.c
SRC_NAME += init_pthread.c
SRC_NAME += fps_text_time.c
SRC_NAME += crosshair.c

OBJ_NAME = $(SRC_NAME:.c=.o)

LIB_NAME = libft.a

INC_PATH = ./includes/
SRC_PATH = ./srcs/
OBJ_PATH = ./objs/
LIB_PATH = ./libft/

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
HEAD = $(addprefix $(INC_PATH), $(INC_NAME))
LIB = $(addprefix $(LIB_PATH), $(LIB_NAME))

#FRAMEWORK = -framework OpenGL -framework AppKit
#MLXFLAG = -I /usr/local/include -L /usr/local/lib -lmlx
SDL2 = -l SDL2 -lm -lSDL2_mixer -lSDL2_ttf
COMPILE_SDL2 = SDL2/lib/libSDL2.a
# `sdl2-config --cflags --libs`
CFLAGS = -g -Wall -Wextra -Werror -lpthread -D_REENTRANT -DLinux
NORMINETTE = ~/.norminette/norminette.rb

$(CC) = clang

###############################################################################

all: $(NAME)

$(NAME): $(OBJ) $(COMPILE_SDL2)
	make -C libft/.
	$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $(NAME) $(SDL2) $(shell ./SDL2/bin/sdl2-config --cflags --libs)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(HEAD) 
	mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) -I $(INC_PATH) -o $@ -c $< 

$(COMPILE_SDL2) :


	if ! dpkg-query -W -f='$${Status}' freeglut3-dev  | grep "ok installed"; \
	then sudo apt-get install freeglut3-dev; fi
	(cd SDL2-2.0.12 \
	&& ./configure --prefix=$(shell pwd)/SDL2 --enable-static --disable-shared \
	&& make \
	&& make install)

clean:
	make clean -C $(LIB_PATH)
	$(RM) -rf $(OBJ_PATH)

fclean: clean debug_clean
	$(RM) $(LIB)
	$(RM) $(NAME)

reset_SDL2:
	$(RM) -r SDL2

re: fclean all

debug: $(COMPILE_SDL2)
	make -C $(LIB_PATH)
	$(CC) -g3 -fsanitize=address,undefined $(CFLAGS) -I $(INC_PATH) $(SRC) $(LIB) $(SDL2) $(shell ./SDL2/bin/sdl2-config --cflags --libs) -lm

debug_clean:
	$(RM) -rf a.out a.out.DSYM
	
norm:
	$(NORMINETTE) $(SRC) $(HEAD) $(LIB_PATH)

.PHONY: clean fclean re all debug debug_clean norm ubuntu
