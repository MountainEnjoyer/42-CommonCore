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
    char src[] = "finsedksefg";
    char dst[] = "debut";
    printf("%zu, %s\n", strlcat(dst, src, 3), dst);
    char sorc[] = "finsedksefg";
    char dest[] = "debut";
    printf("%zu, %s\n", ft_strlcat(dest, sorc, 3), dest);
	return(0);
}
