# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zchauve <zchauve@student.42.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/08/10 17:31:51 by zchauve           #+#    #+#              #
#    Updated: 2026/08/10 17:31:52 by zchauve          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft

CC = cc

CFLAGS = -Werror -Wall -Wextra

HEADER = libft.h

SRC = ft_memset.c

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
	$(CC) $(CFLAGS) -o test main.c -L. $(NAME).a 

ctest: 
	$(RM) test
