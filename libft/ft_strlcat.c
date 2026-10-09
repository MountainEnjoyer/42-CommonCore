/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchauve <zchauve@student.42.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 19:23:02 by zchauve           #+#    #+#             */
/*   Updated: 2026/10/09 19:35:10 by zchauve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t  ft_strlcat(char *dst, const char *src, size_t size)
{
    size_t i;
    size_t srcLen;
    size_t dLen;

    dLen = 0;
    while (dst[dLen] && dLen < size)
        dLen++;
    srcLen = 0;
    while (src[srcLen])
        srcLen++;
    i = 0;
    while ((dLen + i + 1) < size && src[i])
    {
        dst[dLen + i] = src[i];
        i++;
    }
    if (dLen <= size)
        return (dLen + srcLen);
    dst[dLen + i] = '\0';
    return ((dLen + srcLen));
}
