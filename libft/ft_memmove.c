/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_memmove.c                                        :+:    :+:           */
/*                                                      +:+                   */
/*   By: zchauve <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/10/07 15:31:58 by zchauve        #+#    #+#                */
/*   Updated: 2026/10/07 15:58:42 by zchauve        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char temp[n];
	char *s;
	char *d;
	size_t i;

	if (!src)
		return (NULL);
	i = 0;
	s = (char *)src;
	d = (char *)dest;
	while(i < n && s[i])
	{
		temp[i] = s[i];
		i++;
	}
	i = 0;
	while(i < n)
	{
		d[i] = temp[i];
		i++;
	}
	return(dest);
}
