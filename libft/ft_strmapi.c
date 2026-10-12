/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchauve <zchauve@student.42.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 23:53:52 by zchauve           #+#    #+#             */
/*   Updated: 2026/10/12 23:58:34 by zchauve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char *res;
	char *ptr;

	i = 0;
	ptr = (char *)s;
	res = malloc(sizeof(char) * ft_strlen((char *)s));
	while (i < (unsigned int)ft_strlen((char *)s) && ptr[i])
	{
		res[i] = f(i, ptr[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}
