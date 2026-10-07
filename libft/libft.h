/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                             :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: zchauve <zchauve@student.42.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 10:49:10 by zchauve           #+#    #+#             */
/*   Updated: 2026/10/07 20:49:22 by zchauve        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_tolower(int c);
int	ft_toupper(int c);
int	ft_isprint(int c);
int	ft_isascii(int c);
int	ft_isalpha(int c);
int	ft_isdigit(int c);
int	ft_isalnum(int c);
int	ft_atoi(const char *s);
int	ft_strcmp(char *s1, char *s2);
int	ft_strlen(char *s);
int	ft_strncmp(char *s1, char *s2, unsigned int n);
int	ft_memcmp(const void *s1, const void *s2, size_t n);
char		*ft_strstr(char *str, char *to_find);
char		*ft_strdup(char *s);
char		*ft_strcpy(char *dst, char *src);
char	*ft_strncpy(size_t dsize, char dst[dsize], const char *src);
char	*ft_strcat(char *dest, char *src);
char	*ft_strncat(char *dest, char *src, unsigned int nb);
void	ft_makehexa(char *str);
void	dec_to_hex(unsigned int ascii);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_memcpy(size_t n, void *dest, void *src);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
