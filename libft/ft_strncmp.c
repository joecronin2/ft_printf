/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcronin <jcronin@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 14:48:07 by jcronin           #+#    #+#             */
/*   Updated: 2025/10/08 14:48:35 by jcronin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;
	const unsigned char	*us1 = (const unsigned char *)s1;
	const unsigned char	*us2 = (const unsigned char *)s2;

	i = 0;
	while ((us1[i] || us2[i]) && i < n)
	{
		if (us1[i] != us2[i])
			return (us1[i] - us2[i]);
		i++;
	}
	return (0);
}

// int	main(void)
// {
// 	int	a;
//
// 	a = ft_strncmp("aaa", "aaa", 2);
// 	return (0);
// }
