/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchauve <zchauve@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 20:10:49 by zchauve           #+#    #+#             */
/*   Updated: 2026/10/26 00:30:06 by zchauve          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

static char	*freeing(char *buff)
{
	free(buff);
	return (NULL);
}

static int	check(char *s)
{
	char	*p;

	p = s;
	if (!s[0] || !s)
		return (0);
	while (*s && *s != '\n')
		s++;
	return (s - p);
}

static char	*alloc_dup(char *s, char *buffer)
{
	int	i;

	i = 0;
	buffer = malloc(sizeof(char) * (ft_strlen(buffer) + check(s)));
	if (!buffer)
		return(freeing(buffer));
	while (s[i] != '\n')
	{
		if (!s[i])
			return(freeing(buffer));
		buffer[ft_strlen(buffer) + i - 1] = s[i];
		i++;
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	char		buff[BUFFER_SIZE];
	static char	*buffer;

	if (!read(fd, buff, BUFFER_SIZE))
		return (NULL);
	while ((check(buff) == BUFFER_SIZE && check(buff)))
	{
		if (!read(fd, buff, BUFFER_SIZE))
			return (NULL);
		if (check(buff))
		{
			buffer = alloc_dup(buff, buffer);
			if (!buffer)
				return (freeing(buffer));
		}
	}
	if (buffer[ft_strlen(buffer) - 1] != '\n')
		return (freeing(buffer));
	return (buffer);
}
