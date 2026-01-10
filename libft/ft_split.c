/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcronin <jcronin@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 17:11:00 by jcronin           #+#    #+#             */
/*   Updated: 2025/10/08 17:28:10 by jcronin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	find_next_word(const char *str, int *start, int *end, char sep)
{
	while (str[*start] && str[*start] == sep)
		(*start)++;
	*end = *start;
	while (str[*end] && str[*end] != sep)
		(*end)++;
	return (*start < *end);
}

static int	count_strs(const char *str, char sep)
{
	int	count;
	int	start;
	int	end;

	start = 0;
	end = 0;
	count = 0;
	while (find_next_word(str, &start, &end, sep))
	{
		start = end;
		count++;
	}
	return (count);
}

static int	fill_arr(const char *str, char **arr, char sep)
{
	int	start;
	int	end;
	int	i;

	start = 0;
	end = 0;
	i = 0;
	while (find_next_word(str, &start, &end, sep))
	{
		arr[i] = ft_substr(str, start, end - start);
		if (!arr[i])
		{
			while (*arr)
			{
				free(*arr);
				arr++;
			}
			return (0);
		}
		start = end;
		i++;
	}
	arr[i] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	int		size;
	char	**arr;

	size = count_strs(s, c);
	arr = malloc((size + 1) * sizeof(*arr));
	if (!arr)
		return (NULL);
	if (!fill_arr(s, arr, c))
	{
		free(arr);
		return (NULL);
	}
	return (arr);
}

// #include <assert.h>
//
// int	main(void)
// {
// 	int	start;
// 	int	end;
//
// 	start = 0;
// 	find_next_word("abc", &start, &end, ' ');
// 	assert(start == 0);
// 	assert(end == 3);
// 	start = 0;
// 	find_next_word("abc def", &start, &end, ' ');
// 	assert(start == 0);
// 	assert(end == 3);
// 	start = 0;
// 	find_next_word(" def", &start, &end, ' ');
// 	assert(start == 1);
// 	assert(end == 4);
// 	start = 0;
// 	find_next_word("", &start, &end, ' ');
// 	assert(start == 0);
// 	assert(end == 0);
// 	assert(count_strs("aa bb cc dd ee", ' ') == 5);
// 	assert(count_strs("", ' ') == 0);
// 	assert(count_strs("    ", ' ') == 0);
// 	assert(count_strs("aa", ' ') == 1);
// 	return (0);
// }
