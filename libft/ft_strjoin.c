/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchauve <zchauve@student.42.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 22:14:07 by zchauve           #+#    #+#             */
/*   Updated: 2026/10/09 22:28:42 by zchauve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <stdio.h>

char    *ft_strjoin(char const *s1, char const *s2)
{
    char *s3;

    s3 = malloc(sizeof(char) * (ft_strlen((char *)s1) + ft_strlen((char *)s2)));
    if (s3 == NULL)
        return (NULL);
    ft_strcat(s3, (char *)s1);
    ft_strcat(s3, (char *)s2);
    return (s3);
}
