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

	char *s = "ozhdqhdqzudh";
	printf("%p\n", &s);
	char *p = memset(&s, 56, 4);
	printf("%p\n", memset(&s, 56, 4));
	printf("%s\n", p);
	char *t = ft_memset(&s, 56, 4);
	printf("%p\n", ft_memset(&s, 56, 4));
	printf("%s\n", t);
	return (0);
}
