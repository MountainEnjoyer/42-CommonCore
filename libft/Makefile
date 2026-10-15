# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                            :+:    :+:            #
#                                                     +:+ +:+         +:+      #
#    By: zchauve <zchauve@student.42.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/08/10 17:31:51 by zchauve           #+#    #+#              #
#    Updated: 2026/10/09 19:46:47 by zchauve        ########   odam.nl         #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc

CFLAGS = -Werror -Wall -Wextra -g

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
	  ft_memcpy.c \
	  ft_memmove.c \
	  ft_bzero.c \
	  ft_memchr.c \
	  ft_memcmp.c \
	  ft_calloc.c \
	  ft_strchr.c \
	  ft_strrchr.c \
	  ft_strlcpy.c \
	  ft_strlcat.c \
	  ft_substr.c \
	  ft_strjoin.c \
	  ft_strnstr.c \
	  ft_strtrim.c \
	  ft_split.c \
	  ft_itoa.c \
	  ft_putchar_fd.c \
	  ft_putstr_fd.c \
	  ft_putendl_fd.c \
	  ft_putnbr_fd.c \
	  ft_strmapi.c \
	  ft_striteri.c \
	  ft_lstnew.c \
	  ft_lstadd_front.c \
	  ft_lstsize.c \
	  ft_lstlast.c \
	  ft_lstadd_back.c \
	  ft_lstdelone.c \
	  ft_lstclear.c \
	  ft_lstiter.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean:
	$(RM) $(OBJ)
	$(RM) $(NAME)

re: fclean all

test: re
	$(CC) $(CFLAGS) -g unit_test/test.c libft.h $(NAME) -o test_exec
	clear
	./test_exec

ctest: fclean
	$(RM) test_exec	
