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

	if (!s1 && !s2)
		return (NULL);
	if (s2 && !s1)
	{
		s3 = calloc((ft_strlen((char *)s2) + 1), sizeof(char));
		ft_strlcpy(s3, (char *)s2, (ft_strlen((char *)s2) + 1));
		return (s3);
	}
	s3 = calloc((ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1), sizeof(char));
    if (s3 == NULL)
        return (NULL);
    ft_strlcat(s3, (char *)s1, ft_strlen((char *)s1) + 1);
    ft_strlcat(s3, (char *)s2, ft_strlen(s3) + ft_strlen((char *)s1) + 2);
    return (s3);
}
