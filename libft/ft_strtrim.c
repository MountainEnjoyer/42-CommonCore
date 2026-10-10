/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchauve <zchauve@student.42.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 22:54:11 by zchauve           #+#    #+#             */
/*   Updated: 2026/10/09 22:55:42 by zchauve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char    *ft_strtrim(char const *s1, char const *set)
{
	char *new;
	int i;
	int y;

	new = malloc(sizeof(char) * ft_strlen((char *)s1));
	i = 0;
	while (s1[i])
	{
		y = 0;
		while (set[y])
		{
			if (s1[i] == set[y])
				i++;
			y++;
		}
		new[i] = (char)s1[i];
		i++;
	}
	return (new);
}
