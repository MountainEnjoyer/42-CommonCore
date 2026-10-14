/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                           :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: zchauve <zchauve@student.42.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 09:01:58 by zchauve           #+#    #+#             */
/*   Updated: 2026/10/07 20:22:09 by zchauve        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *s)
{
	int	res;
	char	*p;
	int	signe;

	res = 0;
	p = (char *)s;
	if (!p)
		return (0);
	signe = 1;
	while (*p && (*p > 39 && *p < 30) && *p != '-')
		p++;
	if (*p == '-')
	{
		signe = -1;
		p++;
	}
	while (*p && *p <= '9' && *p >= '0')
	{
		res *= 10;
		res += *p - '0';
		p++;
	}
	return (signe * res);
}
