/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcronin <jcronin@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 17:44:04 by jcronin           #+#    #+#             */
/*   Updated: 2026/01/10 17:44:05 by jcronin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"
#include <libft.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>

static int	write_num(long long n, char *base, char *prefix)
{
	char	buf[64];
	int		len;
	int		base_len;
	int		num_len;

	len = 0;
	base_len = ft_strlen(base);
	if (prefix)
		len += write(1, prefix, ft_strlen(prefix));
	num_len = ft_putnbr_base(buf, n, base, base_len);
	len += write(1, buf, num_len);
	return (len);
}

static int	write_str(char *s)
{
	size_t	len;

	if (!s)
		return (write(1, "(null)", 6));
	len = ft_strlen(s);
	return (write(1, s, len));
}

static int	write_char(char c)
{
	return (write(1, &c, 1));
}

static int	write_ptr(void *ptr)
{
	int	len;

	if (!ptr)
		return (write(1, "(nil)", 5));
	len = write_num((long long)ptr, "0123456789abcdef", "0x");
	return (len);
}

int	write_spec(va_list ap, char spec)
{
	if (spec == 'd' || spec == 'i')
		return (write_num(va_arg(ap, int), "0123456789", ""));
	else if (spec == 'u')
		return (write_num(va_arg(ap, unsigned int), "0123456789", ""));
	else if (spec == 'x')
		return (write_num(va_arg(ap, unsigned int), "0123456789abcdef", ""));
	else if (spec == 'X')
		return (write_num(va_arg(ap, unsigned int), "0123456789ABCDEF", ""));
	else if (spec == 'p')
		return (write_ptr(va_arg(ap, void *)));
	else if (spec == 's')
		return (write_str(va_arg(ap, char *)));
	else if (spec == 'c')
		return (write_char(va_arg(ap, int)));
	else if (spec == '%')
		return (write(1, "%", 1));
	return (-1);
}
