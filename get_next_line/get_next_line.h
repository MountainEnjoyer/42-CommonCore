/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchauve <zchauve@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 20:11:09 by zchauve           #+#    #+#             */
/*   Updated: 2026/10/31 20:49:01 by zchauve          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stddef.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

# ifndef FD_MAX
#  define FD_MAX 1024
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char		*get_next_line(int fd);
ssize_t		check_read(int fd, char *stash);
void		rearrange(char *stash);

#endif
