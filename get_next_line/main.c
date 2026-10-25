/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchauve <zchauve@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 21:44:50 by zchauve           #+#    #+#             */
/*   Updated: 2026/10/25 19:20:59 by zchauve          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	int	fd;

	fd = open("./file.txt", O_RDONLY, 1);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	return (0);
}
