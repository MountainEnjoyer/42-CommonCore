/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchauve <zchauve@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 19:38:35 by zchauve           #+#    #+#             */
/*   Updated: 2026/10/31 21:05:53 by zchauve          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	rearrange(char *stash)
{
	int		i;
	int		j;
	char	temp[BUFFER_SIZE + 1];

	i = 0;
	j = 0;
	while (stash[i] != '\n' && stash[i])
		i++;
	while (stash[i])
	{
		temp[j] = stash[i];
		j++;
		i++;
	}
	temp[j] = '\0';
	i = 0;
	while (temp[i])
	{
		stash[i] = temp[i];
		i++;
	}
	stash[i] = '\0';
}

ssize_t	check_read(int fd, char *stash)
{
	ssize_t	n;

	if (stash[0])
		return (1);
	n = read(fd, stash, BUFFER_SIZE);
	if (n > 0)
		stash[n] = '\0';
	return (n);
}
