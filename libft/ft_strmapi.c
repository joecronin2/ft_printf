/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcronin <jcronin@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 14:44:22 by jcronin           #+#    #+#             */
/*   Updated: 2025/10/10 14:44:53 by jcronin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			len;
	char			*new;
	unsigned int	i;

	len = ft_strlen(s);
	new = malloc(len + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new[i] = f(i, s[i]);
		i++;
	}
	new[len] = '\0';
	return (new);
}

// char	addOne(unsigned int i, char c)
// {
// 	return (i + c);
// }
//
// #include <stdio.h>
//
// int	main(void)
// {
// 	char * s = ft_strmapi("1234", addOne);
// 	printf("%s\n", s);
// 	return (0);
// }
