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
    size_t sLen;

    sLen = 0;
    while (src[sLen])
        sLen++;
    i = 0;
    while (i < size && src[i])
    {
        dst[ft_strlen(dst) + i] = src[i];
        i++;
    }
    dst[ft_strlen(dst) + i] = '\0';
    return (sLen);
}
