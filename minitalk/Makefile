# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcho <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/08 17:49:58 by hcho              #+#    #+#              #
#    Updated: 2021/07/05 17:15:42 by hcho             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra
NAME = done
NAME1 = server
NAME2 = client
SRCS1 = server.c util.c
SRCS2 = client.c util.c
SBONUS1 = server_bonus.c util_bonus.c
SBONUS2 = client_bonus.c util_bonus.c
OBJS1 = $(SRCS1:.c=.o)
OBJS2 = $(SRCS2:.c=.o)
OBONUS1 = $(SBONUS1:.c=.o)
OBONUS2 = $(SBONUS2:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(NAME1) $(NAME2)

bonus: $(OBONUS1) $(OBONUS2)
	$(CC) $(CFLAGS) $(OBONUS1) -o $(NAME1)
	$(CC) $(CFLAGS) $(OBONUS2) -o $(NAME2)

$(NAME1): $(OBJS1)
	$(CC) $(CFLAGS) $^ -o $@
	
$(NAME2): $(OBJS2)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -rf $(OBJS1)
	rm -rf $(OBJS2)
	rm -rf $(OBONUS1)
	rm -rf $(OBONUS2)

fclean: clean
	rm -rf $(NAME1) 
	rm -rf $(NAME2) 

re: fclean all

.PHONEY: all clean fclean re
