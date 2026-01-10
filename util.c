/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcronin <jcronin@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 17:46:43 by jcronin           #+#    #+#             */
/*   Updated: 2026/01/10 17:46:44 by jcronin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"
#include <stdlib.h>

char	*ft_strchrnul(const char *s, int c)
{
	while (*s && *s != (char)c)
		s++;
	return ((char *)s);
}

static void	rev_str(char *s, size_t len)
{
	char	tmp;
	size_t	i;
	size_t	j;

	s[len] = '\0';
	i = 0;
	j = len - 1;
	while (i < j)
	{
		tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;
		i++;
		j--;
	}
}

int	ft_putnbr_base(char buf[], long long n, char *base_str, int base_len)
{
	int					i;
	unsigned long long	nb;
	int					start;

	i = 0;
	if (n < 0 && base_len == 10)
	{
		buf[i++] = '-';
		nb = -n;
	}
	else
		nb = (unsigned long long)n;
	start = i;
	if (nb == 0)
		buf[i++] = base_str[0];
	else
	{
		while (nb != 0)
		{
			buf[i++] = base_str[nb % base_len];
			nb /= base_len;
		}
	}
	rev_str(buf + start, i - start);
	return (i);
}
