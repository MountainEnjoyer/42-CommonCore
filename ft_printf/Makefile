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

LIBDIR = libft/
LIB = $(LIBDIR)libft.a $(LIBDIR)libft.h

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c

OBJ = $(SRC:.c=.o)

all = $(NAME)

$(NAME) : $(OBJ)
	$(MAKE) -C $(LIBDIR)
	ar rc $(NAME) $(OBJ) $(LIB)

clean :
	$(MAKE) -C $(LIBDIR) clean
	$(RM) $(OBJ)

fclean :
	$(MAKE) -C $(LIBDIR) fclean
	clean
	$(RM) $(NAME)

re :
	$(MAKE) -C $(LIBDIR) re
	fclean
	all
