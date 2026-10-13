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
	char	*result;

	result = ft_strmapi("hello world", ft_upper);
	printf("Test 2: %s (expected: HELLO WORLD)\n", result);
	free(result);

	result = ft_strmapi("hello", NULL);
	printf("Test 5: %p (expected: NULL)\n", (void *)result);
	free(result);

	return (0);
}
