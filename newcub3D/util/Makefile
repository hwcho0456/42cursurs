# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcho <hcho@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/23 15:53:21 by hcho              #+#    #+#              #
#    Updated: 2021/05/05 21:14:07 by hcho             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

AR = ar
ARFLAGS = rcs
CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = util.a  
SOURCES = ft_concat.c ft_atoi.c check_str.c ft_strcmp.c strutil.c ft_split.c fileutil.c
OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ 

$(NAME): $(OBJECTS)
	ar rcs $@ $(OBJECTS)

clean: 
	rm -f $(OBJECTS) $(OBONUS)

fclean: clean 
	rm -f $(NAME)

re: fclean all
