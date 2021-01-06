# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcho <hcho@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/01 10:33:23 by hcho              #+#    #+#              #
#    Updated: 2021/01/06 12:59:45 by hcho             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

AR = ar
ARFLAGS = rcs
CC = gcc
CFLAGS = -Wall -Werror -Wextra
LIBFT = libft.a
LIBDIR = libft
NAME = libftprintf.a
SRCS = ft_printf.c options.c print_integer.c print_character.c print_realnum.c
OBJS = $(SRCS:.c=.o)

all : $(NAME)

.c.o : 
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) 
		$(AR) $(ARFLAGS) $(NAME) $(OBJS)
clean: 
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONEY: all bonus clean fclean re
