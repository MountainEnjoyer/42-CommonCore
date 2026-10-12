/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                             :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: zchauve <zchauve@student.42.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 10:49:10 by zchauve           #+#    #+#             */
/*   Updated: 2026/10/09 20:42:49 by zchauve        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <string.h>

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
char	*ft_strncpy(char *dst, const char *src, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
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
char	*ft_strrchr(char *s, int c);
char	*ft_strchr(char *s, int c);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
