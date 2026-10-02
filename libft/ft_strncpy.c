/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchauve <zchauve@student.42.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 15:26:29 by zchauve           #+#    #+#             */
/*   Updated: 2026/08/12 15:32:46 by zchauve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(size_t dsize, char dst[dsize], const char *src)
{
	size_t	i;

	i = 0;
	while (i < dsize && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	while (i < dsize)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}
