/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcronin <jcronin@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 15:56:57 by jcronin           #+#    #+#             */
/*   Updated: 2025/10/08 16:08:34 by jcronin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdbool.h>

unsigned long long	ft_strtoull_base(const char *nptr, const char *base,
		size_t base_len)
{
	unsigned long long	res;
	char				*chr;
	size_t				base_idx;

	while (*nptr == base[0])
		nptr++;
	res = 0;
	while (*nptr)
	{
		chr = ft_memchr(base, *nptr, base_len);
		if (!chr)
			break ;
		base_idx = chr - base;
		res = res * base_len + base_idx;
		nptr++;
	}
	return (res);
}

unsigned long long	ft_strtoull(const char *nptr)
{
	while (ft_isspace(*nptr))
		nptr++;
	return (ft_strtoull_base(nptr, "0123456789", 10));
}

long long	ft_strtoll(const char *nptr)
{
	bool		neg;
	long long	res;

	neg = false;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			neg = true;
		nptr++;
	}
	res = ft_strtoull(nptr);
	if (neg)
		return (-res);
	return (res);
}

int	ft_atoi(const char *nptr)
{
	return (int)ft_strtoll(nptr);
}

#include <assert.h>

int	main(void)
{
	assert(ft_strtoull_base("0", "0123456789", 10) == 0);
	assert(ft_strtoull_base("000012345", "0123456789", 10) == 12345);
	assert(ft_strtoull_base("12345", "0123456789", 10) == 12345);
	assert(ft_strtoull_base("10010", "01", 2) == 18);
	assert(ft_strtoull_base("", "", 1) == 0);
	assert(ft_atoi("0") == 0);
	assert(ft_atoi("1234") == 1234);
	assert(ft_atoi("-1234") == -1234);
	assert(ft_atoi("+1234") == 1234);
	return (0);
}
