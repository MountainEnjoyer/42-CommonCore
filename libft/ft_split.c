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

static char	*char_next(char *s, char c)
{
	while (*s && *s == c)
	{
		s++;
	}
	return (s);
}

static int	wcount(char *s, char c)
{
	int	i;
	int	count;
	int	last_char;

	i = 0;
	last_char = i;
	count = 0;
	if (s != NULL)
		count = 1;
	while (s[i])
	{
		if (s[i] == c && last_char + 1 == i)
			last_char++;
		if (s[i] == c && i > 0)
		{
			count++;
			last_char = i;
		}
		i++;
	}
	return (count);
}

static char	*alouette(char **arr, char *p1, char *p2, int index)
{
	arr[index] = calloc((p1 - p2) + 1, sizeof(char));
	if (!arr[index])
	{
		while (arr++)
			free(*arr);
		free(arr);
		return (NULL);
	}
	if (*p1 == '\0')
	{
		ft_strlcpy(arr[index], (const char *)p2, (p1 - p2) + 1);
		index ++;
		arr[index] = NULL;
		return (arr[index]);
	}
	ft_strlcpy(arr[index], (const char *)p2, (p1 - p2) + 1);
	return (arr[index]);
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
	new = calloc(wcount((char *)s, c) + 1, sizeof(char *));
	if (!s || !new)
		return (NULL);
	if (*p2 == c)
		p2++;
	while (*p1++)
	{
		if (*p1 == c)
		{
			new[j] = alouette(new, p1, p2, j);
			p1 = char_next(p1, c);
			p2 = p1;
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
