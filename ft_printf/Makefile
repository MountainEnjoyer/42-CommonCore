# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zchauve <zchauve@student.42.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/18 19:16:26 by zchauve           #+#    #+#              #
#    Updated: 2026/10/20 11:46:52 by zchauve          ###   ########.ch        #
#                                                                              #
# **************************************************************************** #

LIBDIR = libft
LIB = $(LIBDIR)/libft.a 

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(LIB):
	$(MAKE) -C $(LIBDIR)

$(NAME): $(LIB) $(OBJ)
	cp $(LIB) $(NAME)
	ar rcs $(NAME) $(OBJ)

clean:
	$(MAKE) -C $(LIBDIR) clean
	$(RM) -f $(OBJ)

fclean: clean
	$(MAKE) -C $(LIBDIR) fclean
	$(RM) -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
