/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchauve <zchauve@student.42.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 21:22:54 by zchauve           #+#    #+#             */
/*   Updated: 2026/10/16 23:51:11 by zchauve          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sp;
	char	*sub;

	if (!s || ft_strlen((char *)s) < (size_t)start)
		return (ft_calloc(1, sizeof(char)));
	if (ft_strlen((char *)s) < (len + (size_t)start))
		len = ft_strlen((char *)&s[start]);
	sp = (char *)s + start;
	sub = ft_calloc(len + 1, sizeof(char));
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, sp, len + 1);
	return (sub);
}
/*
void main(void)
{
	char src[] = "iciiii laaa";
	int start = 7;
	printf("%s\n", ft_substr(src, start, 4));
}*/
