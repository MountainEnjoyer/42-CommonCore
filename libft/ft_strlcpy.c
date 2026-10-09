/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_strlcpy.c                                        :+:    :+:           */
/*                                                      +:+                   */
/*   By: zchauve <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/10/09 16:33:14 by zchauve        #+#    #+#                */
/*   Updated: 2026/10/09 16:47:43 by zchauve        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t i;

	i = 0;
	while (i < size && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (i);
}
