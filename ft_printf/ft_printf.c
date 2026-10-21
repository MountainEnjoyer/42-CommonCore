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
#include <unistd.h>

static char	*parssing(char *s, ...)
{
	s = s + 2;
	return (s);
}

int	ft_printf(const char *format, ...)
{
	va_list	argptr;
	va_start(argptr, format);

	
	while (*format)
	{
		if (*format == '%')
		{
			*format = parssing((char *)format, va_arg(argptr, void *));
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

