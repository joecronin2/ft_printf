/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcronin <jcronin@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 19:44:55 by jcronin           #+#    #+#             */
/*   Updated: 2025/10/08 14:33:29 by jcronin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strnlen(const char *s, size_t maxlen)
{
	size_t	i;

	i = 0;
	while (s[i] && i < maxlen)
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstlen;
	size_t	i;

	dstlen = ft_strnlen(dst, size);
	if (dstlen == size)
		return (size + ft_strlen(src));
	i = 0;
	while (src[i] && (dstlen + i) < size - 1)
	{
		dst[dstlen + i] = src[i];
		i++;
	}
	if (dstlen + i < size)
		dst[dstlen + i] = '\0';
	while (src[i])
		i++;
	return (dstlen + i);
}

// #include <bsd/string.h>
// #include <stdio.h>
//
// int	main(void)
// {
// 	char	d[70];
//
// 	strcpy(d, "hello ");
// 	printf("exp: %zu: %s\n", strlcat(d, "world", 3), d);
// 	strcpy(d, "hello ");
// 	printf("own: %zu: %s\n", ft_strlcat(d, "world", 3), d);
// 	return (0);
// }
