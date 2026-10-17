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
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (s != NULL)
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
	int	i;

	i = -1;
	arr[index] = malloc(sizeof(char) * (p1 - p2) + 1);
	if (!arr[index])
	{
		while (arr[i++])
			free(arr[i]);
		free(arr);
		return (NULL);
	}
	else if (*p1 == '\0')
	{
		ft_strlcpy(arr[index], (const char *)p2, (p1 - p2) + 1);
		index ++;
		arr[index] = NULL;
		return (arr[index]);
	}
	else if (*p1)
	{
		ft_strlcpy(arr[index], (const char *)p2, (p1 - p2) + 1);
		return (arr[index]);
	}
	else
		return (arr[index] = NULL);
}

char	**ft_split(char const *s, char c)
{
	int		j;
	char	*p1;
	char	*p2;
	char	**new;

	j = 0;
	p1 = (char *)s;
	p2 = (char *)s;
	new = malloc(sizeof(char *) * wcount((char *)s, c) + 1);
	if (!s || !new)
		return (NULL);
	if (*p2 == c)
		p2++;
	while (*p1++)
	{
		if (*p1 == c)
		{
			new[j] = alouette(new, p1, p2, j);
			p2 = (p1 + 1);
			j++;
		}
	}
	new[j] = alouette(new, p1, p2, j);
	return (new);
}
/*
void main(void)
{
	char src[] = "bla bla bla";
	char dst = ' ';

	ft_split(src, dst);
}*/
