/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_strlcpy.c                                        :+:    :+:           */
/*                                                      +:+                   */
/*   By: zchauve <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/10/09 16:33:14 by zchauve        #+#    #+#                */
/*   Updated: 2026/10/09 19:03:52 by zchauve        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
    size_t	sLen;

	i = 0;
    sLen = 0;
    while (src[sLen])
    {
        sLen++;
    }
    while (i < size - 1 && src[i] && size > 0)
    {
		dst[i] = src[i];
		i++;
	}
	while (dst[i] && size > 0)
	{
		dst[i] = '\0';
		i++;
	}
	return (sLen);
}
