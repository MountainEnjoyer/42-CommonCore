/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_calloc.c                                         :+:    :+:           */
/*                                                      +:+                   */
/*   By: zchauve <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/10/07 20:23:22 by zchauve        #+#    #+#                */
/*   Updated: 2026/10/08 18:28:11 by zchauve        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	char *alloc;
	size_t i;

	if (size == 0 || nmemb == 0 || (size == 0 || nmemb == 0))
		return(NULL);
	alloc = malloc(nmemb * size);
	i = 0;
	while (i < size)
	{
		alloc[i] = (char)0;
		i++;
	}
	return((void *)alloc);
}
