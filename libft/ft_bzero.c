/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_bzero.c                                          :+:    :+:           */
/*                                                      +:+                   */
/*   By: zchauve <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/10/07 16:38:11 by zchauve        #+#    #+#                */
/*   Updated: 2026/10/07 17:06:15 by zchauve        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <strings.h>
#include <stdio.h>
void	ft_bzero(void *s, size_t n)
{
	char *p;
	size_t i;

	printf("test");
	p = (char *)s;
	i = 0;
        printf("ye");
	while (i < n)
	{
		p[i] = 0;
		i++;
	}
}
