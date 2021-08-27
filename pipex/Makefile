# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcho <hcho@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/16 15:07:26 by hcho              #+#    #+#              #
#    Updated: 2021/08/16 15:07:27 by hcho             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra
NAME = pipex
SOURCE = main.c pipe.c util.c
BONUS = main_bonus.c pipe.c util.c
OBJECTS = $(SOURCE:.c=.o)
OBONUS = $(BONUS:.c=.o)

.c.o: 
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

all: $(NAME)

bonus: $(OBONUS)
	$(CC) $(CFLAGS) $(OBONUS) -o $(NAME)

clean:
	rm -rf $(OBJECTS)
	rm -rf $(OBONUS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re