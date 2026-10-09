/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                              :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: zchauve <zchauve@student.42.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 17:25:00 by zchauve           #+#    #+#             */
/*   Updated: 2026/10/09 19:03:36 by zchauve        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../libft.h"
#include <bsd/string.h>

int	intArrTesting()
{
	return (0);
}

int	strTesting()
{
	return (0);
}

int	intTesting()
{
	return (0);
}

int	main(void)
{
	char str[] = "akuwh5dkauwdhkawu5hdkauwdagh5awda";
	char *dst = malloc(sizeof(char) * 18);
	printf("%zu, %s\n", strlcpy(dst, str, 33), dst);
	char *dest = calloc(12, sizeof(char));
	printf("%zu, %s\n", ft_strlcpy(dest, str, 33), dest);
	return(0);
}
