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

void	*ft_memset(void *s, int c, size_t n)
{
	char *add;
	size_t	i;

	add = (char *)s;
	i = 0;
	if ((size_t)ft_strlen(add) > n || n <= 0 || add[0] == 0)
		return ((void *) s);
	while (i < n)
	{
		add[i] = (char)c;
		
	}
	return ((void *)s);
}
