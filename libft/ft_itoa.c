/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchauve <zchauve@student.42.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 22:33:53 by zchauve           #+#    #+#             */
/*   Updated: 2026/10/12 22:34:00 by zchauve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	count_digit(long n)
{
	int count;

	count = 0;
	if (n < 0)
	{
		count++;
		n *= -1;
	}
	if (n > 9)
	{
		n = n / 10;
		count += count_digit(n);
	}
	return (count + 1);
}

char	*ft_itoa(int n)
{
	char *result;
	long nb;
	int count;
	int i;

	nb = n;
	count = count_digit(nb);
	result = malloc(sizeof(char) * count + 1);
	i = count - 1 ;
	if (nb < 0)
		nb *= -1;
	while (i >= 0)
	{
		result[i] = (nb % 10) + 48;
		if (nb > 9)
		{
			nb = nb / 10;
		}
		i--;
	}
	if (n < 0)
		result[0] = '-';
	result[count] = '\0';
	return (result);
}
