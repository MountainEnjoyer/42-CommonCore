/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchauve <zchauve@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 20:10:49 by zchauve           #+#    #+#             */
/*   Updated: 2026/10/25 19:41:19 by zchauve          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*freeing(char *buff)
{
	free(buff);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	int			i;
	char		c;

	c = 1;
	i = 0;
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	while (i != BUFFER_SIZE + 1)
	{
		buff[i] = 0;
		i++;
	}
	i = 0;
	while (c && c != '\n' && i <= BUFFER_SIZE)
	{
		if (read(fd, &c, 1) || !c)
			return (freeing(buff));
		buff[i] = c;
		i++;
	}
	if (i > BUFFER_SIZE && buff[i] != '\n')
		return (freeing(buff));
	return (buff);
}
