/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchauve <zchauve@student.42.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 17:25:00 by zchauve           #+#    #+#             */
/*   Updated: 2026/08/14 17:29:00 by zchauve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
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
	char *zebi = "testset";
	printf("%s\n", zebi);
	char *dest = malloc(sizeof(char) * 5);
	printf("%s", (char *)ft_memcpy(5, dest, zebi));
	printf("%s", dest);
	return (0);
}
