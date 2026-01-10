/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcronin <jcronin@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 14:15:35 by jcronin           #+#    #+#             */
/*   Updated: 2025/10/08 14:27:11 by jcronin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != (char)c)
		s++;
	if (c && !*s)
		return (0);
	return ((char *)s);
}

// #include <string.h>
// int main()
// {
// 	ft_strchr("hello world", '\0');
// 	return (0);
// }
