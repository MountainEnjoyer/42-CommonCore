/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ben <Ben@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 14:43:44 by zchauve           #+#    #+#             */
/*   Updated: 2026/11/02 13:52:18 by Ben              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
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

	if (stash)
	{
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
	return (free(s1), NULL);
}

char	*get_next_line(int fd)
{
	char		*lign;
	static char	stash[BUFFER_SIZE + 1];
	int			n;

	lign = NULL;
	if (fd >= 0 && fd < FD_MAX && BUFFER_SIZE > 0)
	{
		n = check_read(fd, stash);
		while (n > 0)
		{
			lign = ft_strjoin(lign, stash);
			if (lign == NULL)
				return (NULL);
			// if (lign[ft_strlen(lign) - 1] == '\n' || (n < BUFFER_SIZE && n > 0))
			if (ft_buflen(stash) > 0 && stash[ft_buflen(stash) - 1] == '\n')
				return (rearrange(stash), lign);
			rearrange(stash);
			n = check_read(fd, stash);
		}
		if (n < 0)
		{
			free(lign);
			lign = NULL;
		}
	}
	return (lign);
}
