/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcronin <jcronin@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 11:55:24 by jcronin           #+#    #+#             */
/*   Updated: 2025/10/07 14:18:20 by jcronin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((const unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

void	*ft_memrcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[n - 1 - i] = ((const unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

void	*ft_memrcpy_items(void *dest, const void *src, size_t n, size_t n_size)
{
	size_t		i;
	void		*d;
	const void	*s;

	i = 0;
	while (i < n)
	{
		d = (void *)((size_t)dest + n_size * i);
		s = (const void *)((size_t)src + n_size * (n - 1 + i));
		ft_memcpy(d, s, n_size);
		i++;
	}
	return (dest);
}

// #include <assert.h>
// #include <string.h>
//
// int	main(int argc, char *argv[])
// {
// 	char	dest[100];
// 	char	src[100];
//
// 	strcpy(src, "abcdef");
// 	ft_memrcpy(dest, src, 6);
// 	dest[6] = '\0';
// 	assert(strcmp(dest, "fedcba") == 0);
// 	return (0);
// }

// int main(int argc, char *argv[])
// {
// 	char *a;
// 	char *b;
// 	ft_memcpy(a, b, 4);
// 	return (0);
// }
