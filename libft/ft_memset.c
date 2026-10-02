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
#include <stdlib.h>

// The memset() function fills the first n bytes of the memory area pointed to by s with the constant byte c.

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned long *add = (unsigned long *)s;
	size_t	i;
	
	i = n;
	i = 0;
	(void)c;
	while (add[i] != NULL)
	{
		dec_to_hex(add[i]);
		i++;
	}
	return ((void *)s);
}
