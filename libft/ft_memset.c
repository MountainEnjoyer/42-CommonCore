/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchauve <zchauve@student.42.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 17:09:21 by zchauve           #+#    #+#             */
/*   Updated: 2026/08/10 17:09:42 by zchauve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

// The memset() function fills the first n bytes of the memory area pointed to by s with the constant byte c.

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		printf("%ld", i);
		*(int *)s = c;
		s++;
		printf("%p\n", s);
		i++;
	}
	return ((void *)s);
}
