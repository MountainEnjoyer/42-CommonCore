/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 ft_split.c											:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: zchauve <zchauve@student.42.ch>			+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2026/10/12 15:47:27 by zchauve		   #+#	  #+#			  */
/*	 Updated: 2026/10/12 16:27:20 by zchauve		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"
#include <stdio.h>

static int	wcount(char *s, char c)
{
	int i;
	int count;

	i = 0;
	count = 1;
	while (s[i])
	{
		if (s[i] == c && i > 0)
			count++;
		i++;
	}
	return (count);
}

static char	*alouette(char **arr, char *p1, char *p2, int index)
{
	int i;

	i = 0;
	arr[index] = malloc(sizeof(char) * (p1 - p2));
	if (!arr[index])
	{
		while (arr[i])
		{
			free(arr[i]);
			i++;
		}
		free(arr);
		return (NULL);
	}
	else
	{
		ft_strlcpy(arr[index], (const char*)p2, p1 - p2);
		return (arr[index]);
	}
}

char	**ft_split(char const *s, char c)
{
	int j;
	char *p1;
	char *p2;
	char **new;

	j = 0;
	p1 = (char *)s;
	p2 = (char *)s;
	new = malloc(sizeof(char *) * wcount((char *)s, c) + 1);
	if (s[0] == '\0' || c == '\0' || !new)
		return ((void *)0);
	if (*p2 == c)
		p2++;
	while (*p1++)
	{
		if (*p1 == c && *p1 > 0)
		{
			new[j] = alouette(new, p1, p2, j);
			j++;
			p2 = p1 + 1;
		}
	}
	new[j] = NULL;
	return (new);
}
