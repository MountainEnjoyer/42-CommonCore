/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_memchr.c                                         :+:    :+:           */
/*                                                      +:+                   */
/*   By: zchauve <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/10/07 17:35:00 by zchauve        #+#    #+#                */
/*   Updated: 2026/10/07 19:50:46 by zchauve        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(void *s, int c, size_t n)
{
	unsigned char *p;
	size_t i;

	p = (unsigned char*)s;
	i = 0;
	while (i < n && p[i])
	{
		if (p[i] == (unsigned char)c)
			return(&s[i]);
		i++;
	}
	return (NULL);
}
