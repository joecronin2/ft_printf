/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcronin <jcronin@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 15:06:06 by jcronin           #+#    #+#             */
/*   Updated: 2025/10/09 15:15:59 by jcronin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*rev_str(const char *src, int len)
{
	int		i;
	char	*str;

	str = malloc(len + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (len > 0)
		str[i++] = src[--len];
	str[i] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	char			buf[16];
	unsigned int	un;
	int				i;

	i = 0;
	if (n < 0)
		un = -n;
	else
		un = n;
	if (un == 0)
		buf[i++] = '0';
	else
	{
		while (un)
		{
			buf[i++] = '0' + (un % 10);
			un /= 10;
		}
	}
	buf[i] = '\0';
	if (n < 0)
		buf[i++] = '-';
	buf[i] = '\0';
	return (rev_str(buf, i));
}

// #include <stdio.h>
// #include <assert.h>
// #include <string.h>
//
// int	main(void)
// {
// 	// printf("%s\n", ft_itoa(1234));
// 	assert(strcmp(ft_itoa(1234), "1234") == 0);
// 	assert(strcmp(ft_itoa(-1234), "-1234") == 0);
// 	assert(strcmp(ft_itoa(0), "0") == 0);
// 	assert(strcmp(ft_itoa(-2147483648), "-2147483648") == 0);
// 	return (0);
// }
