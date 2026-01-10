/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcronin <jcronin@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 16:14:04 by jcronin           #+#    #+#             */
/*   Updated: 2025/10/08 16:41:04 by jcronin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*b;

	len = ft_strlen(s);
	b = malloc(len + 1);
	if (!b)
		return (NULL);
	ft_memcpy(b, s, len + 1);
	return (b);
}
