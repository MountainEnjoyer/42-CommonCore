/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                         :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: zchauve <zchauve@student.42.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 14:33:10 by zchauve           #+#    #+#             */
/*   Updated: 2026/10/07 16:00:43 by zchauve        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(size_t n, void *dest, void *src)
{
	char *d;
	char *s;
	size_t i;	

	d = (char *)dest;
	s = (char *)src;
	i = 0;
	while (i < n && s[i]) {
		d[i] = s[i];
		i++;
	}
	return (dest);
}
