/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcronin <jcronin@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 13:58:59 by jcronin           #+#    #+#             */
/*   Updated: 2025/10/07 14:00:35 by jcronin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 'a' + 'A');
	return (c);
}

// #include <ctype.h>
// #include <stdio.h>
// #include <assert.h>
//
// int	main(void)
// {
// 	for (int i = -1; i < 256; i++){
// 		printf("%d, %d, %d\n", i, toupper(i), ft_toupper(i));
// 		assert(toupper(i) == ft_toupper(i));
// 	}
// 	return (0);
// }
