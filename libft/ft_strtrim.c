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

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char *p1;
	char *p2;
	char *p3;
	char *res;

	p1 = (char *)s1;
	p2 = (char *)s1;
	p3 = (char *)set;
	res = malloc(sizeof(char) * (ft_strlen((char *)s1) + 1));
	if (!res)
		return (NULL);
	while (*p1++)
	{
		p1 = ft_strstr(p1, p3);
		res = p1;
	}
	return (res);
}
