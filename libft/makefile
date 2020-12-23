# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcho <hcho@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/23 15:53:21 by hcho              #+#    #+#              #
#    Updated: 2020/12/23 16:11:24 by hcho             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

TARGET = libft.a  
SOURCES = memset.c bzero.c memcpy.c memccpy.c memmove.c memchr.c memcmp.c \
		  strlen.c strlcpy.c strlcat.c strchr.c strrchr.c strnstr.c strncmp.c \
		  atoi.c isalpha.c isdigit.c isalnum.c isascii.c isprint.c toupper.c tolower.c \
		  calloc.c strdup.c substr.c strjoin.c strtrim.c split.c itoa.c
OBJECTS = $(SOURCES:.c=.o)

all: $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ 

$(TARGET): $(OBJECTS)
	ar rcs -o $@ $(OBJECTS)

clean:
	rm -f $(OBJECTS)

fclean: clean 
	rm -f $(TARGET)

re: fclean all
