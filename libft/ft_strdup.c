/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchauve <zchauve@student.42.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 15:05:12 by zchauve           #+#    #+#             */
/*   Updated: 2026/08/12 15:09:33 by zchauve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(char *s)
{
	int	len;
	int	i;
	char	*dup;

	len = ft_strlen(s);
	dup = (char *)malloc(len * sizeof(char));
	i = -1;
	while (i++ < len)
		dup[i] = s[i];
	dup[i] = '\0';
	return (dup);
}
