/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchauve <zchauve@student.42.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 19:13:20 by zchauve           #+#    #+#             */
/*   Updated: 2026/10/20 11:50:42 by zchauve          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"
#include "libft/libft.h"
#include <unistd.h>

static void	ft_putadr(void *s)
{
	uintptr_t		*adr;
	char			*res;
	unsigned char	c;
	char			*hex;

	hex = "0132456789ABCDEF";
	adr = (uintptr_t *)s;
	res = ft_ultoa(*adr);
	if (!adr)
		return ;
	ft_putstr_fd("0x\0", 1);
	while (*res)
	{
		c = *res;
		ft_putchar_fd(hex[c / 16], 1);
		ft_putchar_fd(hex[c % 16], 1);
		res++;
	}
}

static void	parssing(char c, va_list arg)
{
	if (c == 'c')
		ft_putchar_fd((char)va_arg(arg, int), 1);
	else if (c == 's')
		ft_putstr_fd(va_arg(arg, char*), 1);
	else if (c == 'p')
		ft_putadr(va_arg(arg, void *));
	else if (c == 'd')
		ft_putnbr_fd(va_arg(arg, long), 1);
	else if (c == 'i')
		ft_putnbr_fd(va_arg(arg, int), 1);
	else if (c == 'u')
		ft_putnbr_fd(va_arg(arg, long), 1);
	else if (c == 'x')
		ft_puthexas(va_arg(arg, char *), 0);
	else if (c == 'X')
		ft_puthexas(va_arg(arg, char *), 1);
	else if (c == '%')
		write(1, "%", 1);
}

int	ft_printf(const char *format, ...)
{
	va_list	argptr;
	va_start(argptr, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			parssing(*format, argptr);
		}
		else
			write(1, &*format, 1);
		format++;
	}
	return (0);
}
