/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcronin <jcronin@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 20:00:27 by jcronin           #+#    #+#             */
/*   Updated: 2025/10/10 20:01:32 by jcronin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_putnbr_fd(int n, int fd)
{
	char	*str;

	str = ft_itoa(n);
	ft_putstr_fd(str, fd);
	free(str);
}

// int	main(void)
// {
// 	ft_putnbr_fd(0, 1);
// 	ft_putnbr_fd(5, 1);
// 	ft_putnbr_fd(-5, 1);
// 	ft_putnbr_fd(42, 1);
// 	ft_putnbr_fd(-57, 1);
// 	ft_putnbr_fd(164189, 1);
// 	ft_putnbr_fd(-987441, 1);
// 	ft_putnbr_fd(2147483647, 1);
// 	ft_putnbr_fd(-2147483648LL, 1);
// 	return (0);
// }
