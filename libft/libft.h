/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcronin <jcronin@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 10:58:28 by jcronin           #+#    #+#             */
/*   Updated: 2025/10/11 16:11:05 by jcronin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stddef.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int					ft_islower(int c);
int					ft_isupper(int c);
int					ft_isspace(int c);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);

size_t				ft_strlen(const char *s);
size_t				strnlen(const char *s, size_t maxlen);
char				*ft_strchr(const char *s, int c);
char				*ft_strchrnul(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strrev(const char *str);
char				*ft_strnstr(const char *big, const char *little,
						size_t len);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strdup(const char *s);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);

void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memrcpy(void *dest, const void *src, size_t n);
void				*ft_memrcpy_items(void *dest, const void *src, size_t n,
						size_t n_size);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);

void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);

int					ft_atoi(const char *nptr);
char				*ft_itoa(int n);

void				*ft_calloc(size_t nmemb, size_t size);

void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putendl_fd(char *s, int fd);
