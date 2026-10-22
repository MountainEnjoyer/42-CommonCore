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
	uintptr_t *adr;
	unsigned char c;
	char *hex = "0132456789ABCDEF";

	adr = (uintptr_t *)s;
	while (*adr)
	{
		c = *adr;
		ft_putchar_fd(hex[c / 16], 1);
		ft_putchar_fd(hex[c % 16], 1);
		adr++;
	}
}

static void	parssing(char c, void *data)
{
	if (c == 'c')
		write(1, &data,1);
	else if (c == 's')
		ft_putstr_fd((char *)data, 1);
	else if (c == 'p')
		ft_putadr(&data);
	else if (c == 'd')
		ft_putnbr_fd(*(long *)data, 1);
	else if (c == 'i')
		ft_putnbr_fd(*(long *)data, 1);
	else if (c == 'u')
		ft_putnbr_fd(*(long *)data, 1);
	else if (c == 'x')
		ft_puthexas((char *)data, 0);
	else if (c == 'X')
		ft_puthexas((char *)data, 1);
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
			parssing(*format, va_arg(argptr, void *));
		}
		else
			write(1, &format, 1);
		format++;
	}
	return (0);
}
