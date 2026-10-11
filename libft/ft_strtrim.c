/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchauve <zchauve@student.42.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 22:54:11 by zchauve           #+#    #+#             */
/*   Updated: 2026/10/09 22:55:42 by zchauve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char    *ft_strtrim(char const *s1, char const *set)
{
    char *new;

    new = malloc(sizeof(char) * ft_strlen((char *)s1));
    if (s1 && ft_strnstr(s1, set, ft_strlen((char *)set)))
    {
        new = ft_strnstr(s1, set, ft_strlen((char *)set));
    }
    return (new);
}
