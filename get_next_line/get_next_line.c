/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchauve <zchauve@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 20:10:49 by zchauve           #+#    #+#             */
/*   Updated: 2026/10/28 11:37:57 by zchauve          ###   ########.ch       */
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

static char	*alloc_dup(char *buff, char *buffer)
{
	int	i;
	int	len;
	int	blen;

	i = 0;
	blen = ft_strlen(buffer);
	len = ft_strrchr(buff, '\n');
	if (ft_strrchr(buff, '\n') < 0)
		len = ft_strlen(buff) - 1;
	buffer = malloc(sizeof(char) * (blen + len) + 1);
	if (!buffer)
		return (freeing(buffer));
	while (i < len)
	{
		buffer[blen + i] = buff[i];
		printf("buffer=%s, buff[i]=%c, buffer[blen + i]=%c, blen=%d, len=%d, i=%d\n", buffer, buff[i], buffer[blen + i], blen, len, i);
		i++;
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	char		buff[BUFFER_SIZE];
	char	*buffer;

	if (BUFFER_SIZE > 0 && fd > 0)
	{
		while (read(fd, buff, BUFFER_SIZE))
		{
		if (ft_strrchr(buff, '\0') >=0  && ft_strrchr(buff, '\n') >= 0
				&& (ft_strrchr(buff, '\0') < ft_strrchr(buff, '\n')))
			return (NULL);
		if (ft_strrchr(buff, '\0') >=0 && ft_strrchr(buff, '\n') < 0)
			return (NULL);
		if (ft_strrchr(buff, '\n') >= 0)
			return (alloc_dup(buff, buffer));
		buffer = alloc_dup(buff, buffer);
		}
	}
	return (NULL);
}
