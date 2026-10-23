/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchauve <zchauve@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 09:37:01 by zchauve           #+#    #+#             */
/*   Updated: 2026/10/23 09:39:04 by zchauve          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putunbr_fd(unsigned int n, int fd)
{
	int	count;

	count = 0;
	if (n >= 10)
		count = ft_putunbr_fd(n / 10, fd);
	ft_putchar_fd("0123456789"[n % 10], 1);
	return (count + 1);
}
