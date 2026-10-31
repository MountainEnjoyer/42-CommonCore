/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchauve <zchauve@student.42.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 14:43:44 by zchauve           #+#    #+#             */
/*   Updated: 2026/10/31 21:08:40 by zchauve          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static size_t	ft_strlen(char *s)
{
	char	*p;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	p = (char *)s;
	while (p[i])
		i++;
	return (i);
}

static char	*ft_strjoin(char *s1, char *stash)
{
	char	*s3;
	size_t	i;
	size_t	j;

	if (stash)
	{
		s3 = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(stash) + 1));
		if (!s3)
			return (NULL);
		i = 0;
		j = -1;
		if (s1)
		{
			while (s1[++j])
				s3[i++] = s1[j];
			j = -1;
		}
		while (stash[++j] && stash[j - 1] != '\n')
			s3[i++] = stash[j];
		s3[i] = '\0';
		stash[0] = 0;
		return (s3);
	}
	return (NULL);
}

static int	ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*p;

	i = 0;
	p = (char *)s;
	while (i <= (size_t)ft_strlen(p) - 1)
	{
		if ((unsigned char)p[i] == (unsigned char)c)
		{
			return ((int)i);
		}
		i++;
	}
	return (-1);
}

char	*get_next_line(int fd)
{
	char		*lign;
	static char	stash[BUFFER_SIZE + 1];

	if (fd > 0 && fd < FD_MAX && BUFFER_SIZE > 0)
	{
		while (check_read(fd, stash) > 0)
		{
			if (ft_strrchr(stash, '\n'))
			{
				lign = ft_strjoin(lign, stash);
				return (rearrange(stash), lign);
			}
			else
			{
				rearrange (stash);
				lign = ft_strjoin(lign, stash);
			}
		}
	}
	return (NULL);
}
