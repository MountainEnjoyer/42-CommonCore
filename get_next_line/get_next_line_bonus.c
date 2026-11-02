/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ben <Ben@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 14:43:44 by zchauve           #+#    #+#             */
/*   Updated: 2026/11/02 14:13:32 by zchauve          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>

size_t	ft_buflen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	return (i);
}

static size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

static char	*ft_strjoin(char *s1, char *stash)
{
	char	*s3;
	size_t	i;
	size_t	j;

	if (!stash)
		return (free(s1), NULL);
	s3 = malloc(sizeof(char) * (ft_strlen(s1) + ft_buflen(stash) + 1));
	if (!s3)
		return (free(s1), NULL);
	i = 0;
	j = -1;
	if (s1)
		while (s1[++j])
			s3[i++] = s1[j];
	j = -1;
	while (stash[++j] && stash[j - 1] != '\n')
		s3[i++] = stash[j];
	s3[i] = '\0';
	return (free(s1), s3);
}

char	*get_next_line(int fd)
{
	char		*lign;
	static char	stash[FD_MAX][BUFFER_SIZE + 1];
	int			n;
	int			blen;

	lign = NULL;
	if (fd >= 0 && fd < FD_MAX && BUFFER_SIZE > 0)
	{
		n = check_read(fd, stash[fd]);
		while (n > 0)
		{
			blen = ft_buflen(stash[fd]);
			lign = ft_strjoin(lign, stash[fd]);
			if (lign == NULL)
				return (NULL);
			if (blen > 0 && stash[fd][blen - 1] == '\n')
				return (rearrange(stash[fd]), lign);
			rearrange(stash[fd]);
			n = check_read(fd, stash[fd]);
		}
		if (n < 0)
			return (free(lign), NULL);
	}
	return (lign);
}
