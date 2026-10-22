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

static int	ft_putadr(void *s, int ye, uintptr_t rec, int count)
{
	uintptr_t		adr;
	char			*hex;

	hex = "0132456789abcdef";
	adr = rec;
	if (rec <= 0)
		adr = (uintptr_t)s;
	if (!ye)
		ft_putstr_fd("0x\0", 1);
	if (adr >= 16)
	{
		ft_putadr(s, 1, (adr / 16), count);
	}
	ft_putchar_fd(hex[adr % 16], 1);
	return (count + 1);
}

static int	parssing(char c, va_list arg)
{
	int res;

	res = 1;
	if (c == 'c')
		ft_putchar_fd((char)va_arg(arg, int), 1);
	else if (c == 's')
		res = ft_putstr_fd(va_arg(arg, char*), 1);
	else if (c == 'p')
		res = ft_putadr(va_arg(arg, void *), 0, 0, 0);
	else if (c == 'd')
		res = ft_putnbr_fd(va_arg(arg, int), 1);
	else if (c == 'i')
		res = ft_putnbr_fd(va_arg(arg, int), 1);
	else if (c == 'u')
		res = ft_putnbr_fd(va_arg(arg, long), 1);
	else if (c == 'x')
		res = ft_putnbr_base(va_arg(arg, unsigned int), "0123456789acbdef");
	else if (c == 'X')
		res = ft_putnbr_base(va_arg(arg, unsigned int), "0123456789ACBDEF");
	else if (c == '%')
		write(1, "%", 1);
	else
		return (0);
	return (res);
}

int	ft_printf(const char *format, ...)
{
	va_list	argptr;
	int		count;

	count = 0;
	va_start(argptr, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += parssing(*format, argptr) + 1;
		}
		else
		{
			write(1, &*format, 1);
			count++;
		}
		format++;
	}
	va_end(argptr);
	return (count);
}
