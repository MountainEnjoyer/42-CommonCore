/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                              :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: zchauve <zchauve@student.42.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 17:25:00 by zchauve           #+#    #+#             */
/*   Updated: 2026/10/09 16:49:54 by zchauve        ########   odam.nl        */
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
	char dst[15];
	printf("%zu\n%zu", ft_strlcpy(dst, str, 15), strlcpy(dst ,str, 15));
	return(0);
}
