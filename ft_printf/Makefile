# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcho <hcho@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/01 10:33:23 by hcho              #+#    #+#              #
#    Updated: 2021/01/01 11:59:38 by hcho             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

AR = ar
ARFLAGS = rcs
CC = gcc
CFLAGS = -Wall -Werror -Wextra
LIBFT = libft.a
LIBDIR = libft
NAME = libftprintf.a
SRCS = main.c
OBJS = $(SRCS:.c=.o)

all : $(NAME)

.c.o : 
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT)
		cp $(LIBDIR)/$(LIBFT) ./$(NAME)
		$(AR) $(ARFLAGS) $@ $(OBJS)

$(LIBFT): 
	$(MAKE) -C $(LIBDIR)

clean: 
		rm -f $(OBJS)
		$(MAKE) clean -C $(LIBDIR)

fclean: 
		rm -f $(OBJS)
		rm -f $(NAME)
		$(MAKE) fclean -C $(LIBDIR)

re: fclean all

.PHONEY: all bonus clean fclean re
