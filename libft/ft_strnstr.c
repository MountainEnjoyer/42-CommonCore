/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchauve <zchauve@student.42.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 14:36:05 by zchauve           #+#    #+#             */
/*   Updated: 2026/10/15 14:36:08 by zchauve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char    *ft_strnstr(const char *big, const char *little, size_t len)
{
    size_t i;
    size_t y;
    char *p1;

	if (!little || (!big && !len))
		return ((char *)big);
	i = 0;
    p1 = (char *)big;
    if (!p1 || len > ft_strlen(p1) || len < ft_strlen((char*)little))
        return (NULL);
    while (p1[i] && i < len)
    {
        y = 0;
        while (p1[i + y] == little[y] && little[y] && p1[i + y])
            y++;
        if (y == ft_strlen((char *)little))
            return (&p1[i]);
        i++;
    }
    return (NULL);
}
