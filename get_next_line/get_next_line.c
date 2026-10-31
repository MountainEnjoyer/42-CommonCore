/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchauve <zchauve@student.42.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 14:43:44 by zchauve           #+#    #+#             */
/*   Updated: 2026/10/29 14:43:51 by zchauve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_strlen(const char *s)
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

static char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	tot_size;
	size_t	i;
	size_t	j;

	if (s2)
	{
		tot_size = ft_strlen((char *)s1) + ft_strlen((char *)s2);
		s3 = (char *)malloc(sizeof(char) * (tot_size + 1));
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
		while (s2[++j] && s2[j - 1] != '\n')
			s3[i++] = s2[j];
		s3[i] = '\0';
		return (s3);
	}
	return (NULL);
}

static char	*allouette(char *stash, char *buff)
{
	if (stash == NULL)
		stash = ft_strjoin(stash, buff);
	return (stash);
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
	char		*buff;
	static char	*stash;
	//char		*lign;

	if (!stash)
		stash = NULL;
	if (fd > 0 && BUFFER_SIZE > 0)
	{
		buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buff)
			return (free(stash), NULL);
		while (read(fd, buff, BUFFER_SIZE) > 0)
		{
			if (ft_strrchr(buff, '\n'))
				return (allouette(stash, buff));
		}
	}
	return (NULL);
}
