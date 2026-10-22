/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchauve <zchauve@student.42.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 23:32:32 by zchauve           #+#    #+#             */
/*   Updated: 2026/10/20 10:54:25 by zchauve          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int	ft_putnbr_fd(int n, int fd)
{
	char	*s;

	s = ft_itoa(n);
	if (!s)
		return (0);
	ft_putstr_fd(s, fd);
	free(s);
	return ((int)ft_strlen((const char *)s));
}
