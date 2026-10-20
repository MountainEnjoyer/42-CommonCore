/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchauve <zchauve@student.42.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 19:14:03 by zchauve           #+#    #+#             */
/*   Updated: 2026/10/20 11:47:52 by zchauve          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifdef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <string.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);

#endif
