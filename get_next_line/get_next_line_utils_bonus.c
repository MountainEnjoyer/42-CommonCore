/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ben <Ben@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 19:38:35 by zchauve           #+#    #+#             */
/*   Updated: 2026/11/02 14:06:20 by zchauve          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	clear(char *stash)
{
	int	i;

	i = 0;
	while (stash[i])
		stash[i++] = '\0';
}

void	rearrange(char *stash)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	while (stash[i])
	{
		stash[j] = stash[i];
		j++;
		i++;
	}
	stash[j] = '\0';
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
