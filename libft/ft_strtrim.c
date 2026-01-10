/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcronin <jcronin@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 16:54:55 by jcronin           #+#    #+#             */
/*   Updated: 2025/10/08 17:07:03 by jcronin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char c, const char *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	start;
	int	end;

	start = 0;
	end = ft_strlen(s1) - 1;
	while (is_in_set(s1[start], set))
		start++;
	if (start < end)
		while (is_in_set(s1[end], set))
			end--;
	return (ft_substr(s1, start, end - start + 1));
}

// #include <assert.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
//
// int	main(void)
// {
// 	char	*s;
// 	char	s1[] = "amet";
//
// 	assert(strcmp("a", ft_strtrim(".a", ".")) == 0);
// 	assert(strcmp("a", ft_strtrim("a.", ".")) == 0);
// 	assert(strcmp("a", ft_strtrim(".a.", ".")) == 0);
// 	assert(strcmp("", ft_strtrim(".", ".")) == 0);
// 	assert(strcmp("", ft_strtrim("..", ".")) == 0);
// 	assert(strcmp("", ft_strtrim("", ".")) == 0);
// 	// printf("%s\n", ft_strtrim(s1, "te"));
// 	// char	s1[] = "lorem \n ipsum \t dolor \n sit \t amet";
// 	// printf("%s\n", ft_strtrim("  test test  ", " "));
// 	// printf("%s\n", ft_strtrim("../././.hallo123.//././/.", "./"));
// 	printf("%s\n", ft_strtrim("..", "./"));
// 	printf("%s\n", ft_strtrim("hallo", "./"));
// 	// char *strtrim = ft_strtrim(s1, " ");
// 	// if (!strtrim)
// 	// 	printf("NULL");
// 	// else
// 	// 	printf("%s\n", strtrim);
// 	// if (strtrim == s1)
// 	// 	printf("\nA new string was not returned");
// 	return (0);
// }
