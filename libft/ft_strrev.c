#include "libft.h"
#include <stdlib.h>

char	*ft_strrev(const char *str)
{
	char	*res;
	size_t	len;

	len = ft_strlen(str);
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	ft_memrcpy(res, str, len);
	res[len] = '\0';
	return (res);
}

// #include <assert.h>
// #include <string.h>
//
// int	main(void)
// {
// 	assert(strcmp(ft_strrev("abcdef"), "fedcba") == 0);
// 	assert(strcmp(ft_strrev(""), "") == 0);
// 	return (0);
// }
