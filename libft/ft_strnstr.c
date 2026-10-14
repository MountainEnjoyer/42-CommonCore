/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchauve <zchauve@student.42.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 17:45:54 by zchauve           #+#    #+#             */
/*   Updated: 2026/10/11 17:46:57 by zchauve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char    *ft_strnstr(const char *big, const char *little, size_t len)
{
    size_t i;
    size_t y;
    char *p1;

    i = 0;
    p1 = (char *)big;
    if (little[0] == '\0')
        return (NULL);
    while (p1[i] && i < len)
    {
        y = 0;
        while (p1[i + y] == little[y] && little[y] && p1[i + y])
            y++;
        if (y == ft_strlen((char *)little) - 1)
            return (&p1[i]);
        i++;
    }
    return (p1);
}
