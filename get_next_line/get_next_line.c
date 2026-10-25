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

static char	*g_buffer;

static int	ft_strlen(char *s)
{
	int	i;

	i = 0;
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

static int	alloc_dup(char *s)
{
	int	i;

	i = 0;
	g_buffer = malloc(sizeof(char) * (ft_strlen(g_buffer) + check(s)));
	if (!g_buffer)
	{
		freeing(g_buffer);
		return (0);
	}
	while (s[i] != '\n')
	{
		if (!s[i])
		{
			freeing(g_buffer);
			return (0);
		}
		g_buffer[ft_strlen(g_buffer) + i] = s[i];
		i++;
	}
	return (1);
}

char	*get_next_line(int fd)
{
	char		buff[BUFFER_SIZE];
	int			i;

	i = 0;
	buff[0] = 0;
	while ((check(buff) == BUFFER_SIZE && check(buff)) || i == 0)
	{
		if (!read(fd, buff, BUFFER_SIZE))
			return (NULL);
		if (check(buff))
			if (!alloc_dup(buff))
				return (NULL);
		printf("%s\n", buff);
		i = 1;
	}
	if (g_buffer[ft_strlen(g_buffer) - 1] != '\n')
		return (freeing(g_buffer));
	return (g_buffer);
}
