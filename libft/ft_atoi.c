/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchauve <zchauve@student.42.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 09:01:58 by zchauve           #+#    #+#             */
/*   Updated: 2026/10/18 15:24:36 by zchauve          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *s)
{
	int		res;
	char	*p;
	int		signe;

	res = 0;
	p = (char *)s;
	if (!p)
		return (0);
	signe = 1;
	while (*p && (*p >= 0 && *p <= 32) && *p != '-' && *p != '+')
		p++;
	if (*p == '-')
	{
		signe = -1;
		p++;
	}
	if (*p == '+')
		p++;
	while (*p && *p <= '9' && *p >= '0')
	{
		res *= 10;
		res += *p - '0';
		p++;
	}
	return (signe * res);
}
