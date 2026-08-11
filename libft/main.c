/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchauve <zchauve@student.42.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 19:50:59 by zchauve           #+#    #+#             */
/*   Updated: 2026/08/10 19:52:12 by zchauve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	(void)av;
	(void)ac;

	char s[10];
	//printf("%s\n", (char *)memset(s, 'a', 10 * sizeof(char)));
	printf("%s\n", (char *)ft_memset(s, 'a', 10 * sizeof(char)));
	return (0);
}
