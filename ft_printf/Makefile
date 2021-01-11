# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcho <hcho@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/01 10:33:23 by hcho              #+#    #+#              #
#    Updated: 2021/01/11 17:51:58 by hcho             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
.PHONEY: all bonus clean fclean re test

AR = ar
ARFLAGS = rcs
CC = gcc
CFLAGS = -Wall -Werror -Wextra
LIBFT = libft.a
LIBDIR = libft
NAME = libftprintf.a
SRCS = ft_printf.c options.c print_integer.c print_d_utils.c print_u_utils.c print_hex_utils.c print_character.c print_realnum.c
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

test:
	rm -rf a.out
	gcc -Wall -Wextra main.c ft_printf.c options.c print_character.c  print_integer.c print_d_utils.c print_u_utils.c print_hex_utils.c print_realnum.c print_f_utils.c print_real_utils.c
