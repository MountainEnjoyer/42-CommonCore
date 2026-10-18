/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchauve <zchauve@student.42.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 14:36:05 by zchauve           #+#    #+#             */
/*   Updated: 2026/10/18 14:22:41 by zchauve          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	y;
	char	*p1;

	if (!little[0] && !big[0] && len == 0)
		return ((char *)big);
	if (len <= 0 || ft_strlen((char *)little) > len)
		return (NULL);
	if (ft_strlen((char *)little) == 0 || (big == little))
		return ((char *)big);
	i = 0;
	p1 = (char *)big;
	while (p1[i] && i < len)
	{
		y = 0;
		while (p1[i + y] == little[y] && little[y] && p1[i + y] && i + y < len)
			y++;
		if (y == ft_strlen((char *)little))
			return (p1 + i);
		i++;
	}
	return (0);
}
