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
#include <unistd.h>

static void	put_uint(unsigned int n, int fd)
{
	char	digit;

	if (n < 10)
	{
		digit = '0' + n;
		write(fd, &digit, 1);
	}
	else
	{
		put_uint(n / 10, fd);
		digit = '0' + (n % 10);
		write(fd, &digit, 1);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	put_uint(n, fd);
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
