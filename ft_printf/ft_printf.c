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
	char *adr;

	adr = (char *)s + ft_strlen((char *)s);
	while (adr != (char *)s[0])
	{
		ft_puthexa(*adr);
		adr--;
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
		ft_putnbr_fd((int)data, 1);
	else if (c == 'i')
		ft_putnbr_fd((int)data, 1);
	else if (c == 'u')
		ft_putnbr_fd((int)data, 1);
	else if (c == 'x')
		ft_puthexa((char *)data);
	else if (c == 'X')
		ft_putuphexa((char *)data);
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
			parssing(*format, va_arg(argptr, void *));
			format++;
		}
		else
			write(1, &format, 1);
		format++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	if (ac == 2)
		ft_printf(av[0], av[1]);
	return (0);
}

