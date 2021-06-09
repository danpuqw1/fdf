# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dteemo <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/11 18:25:39 by student           #+#    #+#              #
#    Updated: 2020/08/11 18:25:43 by student          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY:	all clean fclean re

CFLAGS+=-Wno-deprecated-declarations

NAME = fdf

SRC = draw.c main.c map.c util.c

INCS = /usr/X11/include

all:	$(NAME)

$(NAME):	$(SRC)
	make -C libft
	make -C minilibx_macos
	gcc -Wall -Wextra -Werror $(SRC) -I fdf.h -L./minilibx_macos -lmlx -framework OpenGL -framework AppKit -L./libft -lft -o $(NAME)

clean:
	make -C libft clean
	make -C minilibx_macos clean
	/bin/rm -rf $(OBJ)

fclean: clean
	make -C libft fclean
	/bin/rm -rf $(NAME)

re:	fclean all
