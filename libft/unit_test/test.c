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
	char dst[] = "alwdhawkduj0alwdhhalwidawda0wD KHdkAHWDiuauhw0dLIUAHWDiuaHWDiu0AHWDiuHA WpiiUAWHdiuAHW0diuaHHWDpiuAHWDPOu0ahwpodjaowidj AOwduAP0OWdhpaIUUHDaIPUW0D";
	char c = '0';
    char **split = ft_split(dst, c) ;

    int i = 0;
    while (split[i])
    {
        printf("%s\n", split[i]);
        i++;
    }
    free(split);

	return(0);
}
