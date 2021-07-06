# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcho <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/17 13:03:22 by hcho              #+#    #+#              #
#    Updated: 2021/05/05 18:17:56 by hcho             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX = -lmlx -framework OpenGL -framework AppKit
NAME = cub3D
LIB = util.a
LIBPATH = util/
GAMEPATH = game/
KEYPATH = key/
SRCS = 	main.c \
		$(GAMEPATH)game.c $(GAMEPATH)set_game.c $(GAMEPATH)check_map.c $(GAMEPATH)load_map.c \
		$(KEYPATH)key.c
OBJS = $(SRCS:.c=.o)

all : $(NAME)

.c.o : 
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	$(MAKE) -C util
	$(CC) $(CFLAGS) -o $(NAME) $(LIBPATH)$(LIB) $(OBJS) $(MLX)

clean :
	rm -f $(OBJS)
	make clean -C $(LIBPATH)

fclean : clean
	rm -f $(NAME)
	rm -f $(LIBPATH)$(LIB)

re : fclean all

.PHONY: all clean fclean re 
