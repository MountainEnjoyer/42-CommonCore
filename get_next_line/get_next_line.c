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

static char	*alloc_dup(char buff[BUFFER_SIZE], char *buffer)
{
	int	i;
	int	len;
	int	blen;

	i = 0;
	blen = ft_strlen(buffer);
	len = ft_strrchr(buff, '\n');
	if (ft_strrchr(buff, '\n') == 0)
		len = ft_strlen(buff);
	buffer = malloc(sizeof(char) * (ft_strlen(buffer) + len));
	if (!buffer)
		return(freeing(buffer));
	while (i <= len)
	{
		buffer[blen + i] = buff[i];
		i++;
	}
	return (buffer);
}

static char	*init_buff(char buff[BUFFER_SIZE])
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		buff[i] = 0;
		i++;
	}
	return (buff);
}

char	*get_next_line(int fd)
{
	char		buff[BUFFER_SIZE];
	static char	*buffer;

	init_buff(buff);
	if (BUFFER_SIZE > 0)
	{
		while (!ft_strrchr(buff, '\n'))
		{
			if (!read(fd, buff, BUFFER_SIZE))
				return (NULL);
			if ((ft_strrchr(buff, '\0') < ft_strrchr(buff, '\n')) || (ft_strrchr(buff, '\0') && !ft_strrchr(buff, '\n')))
				return (NULL);
			buffer = alloc_dup(buff, buffer);
		}
	}
	return (buffer);
}
