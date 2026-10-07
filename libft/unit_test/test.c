/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                              :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: zchauve <zchauve@student.42.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 17:25:00 by zchauve           #+#    #+#             */
/*   Updated: 2026/10/07 20:16:53 by zchauve        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../libft.h"

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
	char zebi[] = "ksue4awd35awd35";
	char bize[] = "kwda3w5dadw";
	//char *dest = malloc(sizeof(char) * 5);
	//printf("%s", dest);
	if (memcmp(zebi, bize, 5) == ft_memcmp(zebi, bize, 5))
		printf("tout bon");
	else 
		printf("pas bon, %d\n %d", memcmp(zebi, bize, 5), ft_memcmp(zebi, bize, 5));
	//printf("%s\n", (char *)ft_memchr(zebi, '4', 7));
	//printf("%s", zebi);
	return (0);
}
