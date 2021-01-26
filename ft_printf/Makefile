# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcho <hcho@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/01 10:33:23 by hcho              #+#    #+#              #
#    Updated: 2021/01/21 13:06:06 by hcho             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
.PHONEY: all bonus clean fclean re test

AR = ar
ARFLAGS = rcs
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft.a
LIBDIR = libft
NAME = libftprintf.a
SRCS =   ft_printf.c options.c print_character.c print_integer.c print_d_utils.c print_u_utils.c print_x_utils.c print_o_utils.c \
		 print_realnum.c print_f_utils.c print_e_utils.c print_real_utils.c print_p_utils.c
OBJS = $(SRCS:.c=.o)

all : $(NAME)

.c.o : 
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
		  $(AR) $(ARFLAGS) $(NAME) $(OBJS)

bonus : $(OBJS)
		$(AR) $(ARFLAGS) $(NAME) $(OBJS)

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all

test:
	rm -rf a.out
	gcc -Wall -Wextra main.c ft_printf.c options.c print_character.c print_integer.c print_d_utils.c print_u_utils.c print_x_utils.c print_o_utils.c print_realnum.c print_f_utils.c print_e_utils.c print_real_utils.c print_p_utils.c
