/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcronin <jcronin@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 14:55:39 by jcronin           #+#    #+#             */
/*   Updated: 2025/10/13 15:17:21 by jcronin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	little_len;

	if (!*little)
		return ((char *)big);
	little_len = ft_strlen(little);
	if (little_len > len)
		return (NULL);
	i = 0;
	while (big[i] && i <= len - little_len)
	{
		if (big[i] == little[0])
			if (ft_strncmp(&big[i], little, little_len) == 0)
				return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}

// abcdef len > 5
//   cde  littlelen = 3

// #include <assert.h>
// #include <stdio.h>
// #include <string.h>
//
// int	main(void)
// {
// 	char	*s;
// 	char	haystack[30] = "aaabcabcd";
// 	char	needle[10] = "aabc";
//
// 	assert(ft_strnstr(haystack, needle, 0) == 0);
// 	// s = "bbaaaahaisnehanosehi";
// 	// assert(ft_strnstr(s, "aaaa", 20) == s + 2);
// 	// assert(ft_strnstr(s, "aaaa", 5) == NULL);
// 	return (0);
// }
