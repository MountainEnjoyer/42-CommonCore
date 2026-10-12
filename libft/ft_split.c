/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchauve <zchauve@student.42.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 15:47:27 by zchauve           #+#    #+#             */
/*   Updated: 2026/10/12 16:27:20 by zchauve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char    **ft_split(char const *s, char c)
{
    int i;
    int y;
    int j;
    char *p1;
    char **new;

    i = 0;
    y = 0;
    j = 0;
    p1 = (char *)s;
    new = malloc(sizeof(char **));
    if (s[0] == '\0' || c == '\0')
        return (NULL);
    while (p1[i])
    {
        if (p1[i] == c)
        {
            new[y] = malloc(sizeof(char) * (i - j));
            new[y] = ft_strncpy(new[y], &s[j], i - j + 1);
            y++;
            j = i + 1;
        }
        i++;
    }
    new[y] = NULL;
    return (new);
}
