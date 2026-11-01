/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchauve <zchauve@student.42.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 14:43:44 by zchauve           #+#    #+#             */
/*   Updated: 2026/11/01 16:30:20 by zchauve          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

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
		s3 = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(stash) + 1));
		if (!s3)
			return (NULL);
		i = 0;
		j = -1;
		if (s1)
			while (s1[++j])
				s3[i++] = s1[j];
		j = -1;
		while (stash[++j] && stash[j - 1] != '\n')
			s3[i++] = stash[j];
		s3[i] = '\0';
		return (s3);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		*lign;
	char		*temp;
	static char	stash[BUFFER_SIZE + 1];

	lign = NULL;
	if (fd > 0 && fd < FD_MAX && BUFFER_SIZE > 0)
	{
		while (check_read(fd, stash) > 0)
		{
			lign = ft_strjoin(lign, stash);
			if (lign[ft_strlen(lign) - 1] == '\n')
				return (rearrange(stash), lign);
			rearrange(stash);
		}
	}
	return (NULL);
}
