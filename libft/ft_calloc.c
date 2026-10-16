/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchauve <marvin@42.fr>                        +#+                    */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 20:23:22 by zchauve        #+#    #+#                */
/*   Updated: 2026/10/16 14:23:19 by zchauve          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*alloc;
	size_t	i;

	if (size == 0 || nmemb == 0 || (nmemb * size) >= 4294967295)
		return (malloc(1));
	alloc = malloc(nmemb * size);
	if (!alloc)
		return (NULL);
	i = 0;
	while (i < (nmemb * size))
	{
		alloc[i] = '\0';
		i++;
	}
	return ((void *)alloc);
}
