# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcho <hcho@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/28 16:33:07 by hcho              #+#    #+#              #
#    Updated: 2022/01/04 14:30:13 by hcho             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ARCH = arch -x86_64
CC = gcc
CFLAGS = -Wall -Werror -Wextra
MLX = -L mlx_beta -lmlx -framework Metal -framework Metalkit
LIB = libmlx.dylib
NAME = fractol
SRCS = main.c error.c set.c hook.c draw.c
OBJS = $(SRCS:.c=.o)

.c.o: 
	$(ARCH) $(CC) $(CFLAGS) -c $< -o $@ 

$(NAME): $(OBJS)
	$(ARCH) $(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX)
	install_name_tool -change $(LIB) mlx_beta/$(LIB) $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
