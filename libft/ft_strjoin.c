/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcronin <jcronin@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 16:43:10 by jcronin           #+#    #+#             */
/*   Updated: 2025/10/08 16:54:39 by jcronin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*b;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	b = malloc(s1_len + s2_len + 1);
	if (!b)
		return (NULL);
	ft_memcpy(b, s1, s1_len);
	ft_memcpy(b + s1_len, s2, s2_len + 1);
	return (b);
}

// #include <string.h>
// #include <assert.h>
//
// int	main(void)
// {
// 	assert(strcmp(ft_strjoin("aaa", "bbb"), "aaabbb") == 0);
// 	assert(strcmp(ft_strjoin("", "bbb"), "bbb") == 0);
// 	assert(strcmp(ft_strjoin("aaa", ""), "aaa") == 0);
// 	assert(strcmp(ft_strjoin("", ""), "") == 0);
// 	return (0);
// }
