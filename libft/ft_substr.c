/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchauve <zchauve@student.42.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 21:22:54 by zchauve           #+#    #+#             */
/*   Updated: 2026/10/09 21:28:18 by zchauve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
    char *sp;
    char *sub;

    sp = (char *)s + start;
    sub = malloc(sizeof(char) * len);
    ft_memcpy(len, sub, sp);
    sub[len] = '\0';
    return (sub);
}
