/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                           :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: zchauve <zchauve@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 10:58:10 by zchauve           #+#    #+#             */
/*   Updated: 2026/07/09 16:51:02 by zchauve        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	dec_to_hex(unsigned int ascii)
{
	unsigned int	c;
	char *const		hex = "0123456789abcdef";

	c = ascii;
	ft_putchar(hex[c / 16]);
	ft_putchar(hex[c % 16]);
}

void	ft_makehexa(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 32 || str[i] > 126)
		{
			write(1, "\\", 1);
			dec_to_hex(str[i]);
		}
		else
		{
			write(1, &str[i], 1);
		}
		i++;
	}
}
/*
#include <stdio.h>

int     main(void)
{
	char    *str = "Hello\xFF How are you?";
	ft_putstr_non_printable(str);
}*/
