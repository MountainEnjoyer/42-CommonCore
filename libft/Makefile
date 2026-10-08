# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                            :+:    :+:            #
#                                                     +:+ +:+         +:+      #
#    By: zchauve <zchauve@student.42.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/08/10 17:31:51 by zchauve           #+#    #+#              #
#    Updated: 2026/10/08 19:02:54 by zchauve        ########   odam.nl         #
#                                                                              #
# **************************************************************************** #

NAME = libft

CC = cc

CFLAGS = -Werror -Wall -Wextra

HEADER = libft.h

SRC = ft_isascii.c \
	  ft_memset.c \
	  ft_toupper.c \
	  ft_isalnum.c \
	  ft_isdigit.c \
	  ft_isalpha.c \
	  ft_isprint.c \
	  ft_tolower.c \
	  ft_atoi.c \
	  ft_strcmp.c \
	  ft_strlen.c \
	  ft_strncmp.c \
	  ft_strstr.c \
	  ft_strdup.c \
	  ft_strcpy.c \
	  ft_strncpy.c \
	  ft_strcat.c \
	  ft_strncat.c \
	  ft_makehexa.c \
	  ft_memcpy.c \
	  ft_memmove.c \
	  ft_bzero.c \
	  ft_memchr.c \
	  ft_memcmp.c \
	  ft_calloc.c \
	  ft_strchr.c \
	  ft_strrchr.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME).a $(OBJ) $(HEADER)

clean:
	$(RM) $(OBJ)

fclean:
	$(RM) $(OBJ)
	$(RM) $(NAME).a

re: fclean all

test: re
	$(CC) $(CFLAGS) -o test_exec unit_test/test.c -L. $(NAME).a 
	clear
	./test_exec

ctest: fclean
	$(RM) test_exec	
