/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcronin <jcronin@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 16:20:35 by jcronin           #+#    #+#             */
/*   Updated: 2025/10/10 19:56:15 by jcronin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*b;
	size_t	maxlen;

	maxlen = ft_strlen(s);
	if (start >= maxlen)
		return (ft_strdup(""));
	if (start + len > maxlen)
		len = maxlen - start;
	b = malloc(len + 1);
	if (!b)
		return (NULL);
	ft_memcpy(b, s + start, len);
	b[len] = '\0';
	return (b);
}

// #include <assert.h>
// #include <string.h>
// int main() {
//   assert(strcmp(ft_substr("0123456789", 4, 10), "456789") == 0);
//   assert(strcmp(ft_substr("0123456789", 20, 1), "") == 0);
//   return (0);
// }
