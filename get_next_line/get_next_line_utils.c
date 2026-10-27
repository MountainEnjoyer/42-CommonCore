/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchauve <zchauve@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 19:38:35 by zchauve           #+#    #+#             */
/*   Updated: 2026/10/25 19:38:39 by zchauve          ###   ########.ch       */
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

int	ft_strrchr(const char *s, int c)
{
	size_t	i;
	size_t	count;
	char	*p;
	int		found;

	i = 0;
	found = 0;
	count = 0;
	p = (char *)s;
	while (i <= (size_t)ft_strlen(p))
	{
		if ((unsigned char)p[i] == (unsigned char)c)
		{
			return (i);
		}
		i++;
	}
	return (0);
}
