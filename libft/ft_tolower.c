/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcronin <jcronin@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 13:59:14 by jcronin           #+#    #+#             */
/*   Updated: 2025/10/07 14:00:10 by jcronin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c - 'A' + 'a');
	return (c);
}

// #include <ctype.h>
// #include <stdio.h>
// #include <assert.h>
//
// int	main(void)
// {
// 	for (int i = -1; i < 256; i++){
// 		printf("%d, %d, %d\n", i, tolower(i), ft_tolower(i));
// 		assert(tolower(i) == ft_tolower(i));
// 	}
// 	return (0);
// }
