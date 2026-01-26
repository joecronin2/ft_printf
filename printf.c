/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcronin <jcronin@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 17:56:07 by jcronin           #+#    #+#             */
/*   Updated: 2026/01/10 17:56:08 by jcronin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"
#include "write.h"
#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <unistd.h>

static int	ft_vprintf(const char *fmt, va_list ap)
{
	const char	*next = fmt;
	int			written;
	int			a;

	if (!fmt)
		return (-1);
	written = 0;
	while (*next)
	{
		next = ft_strchrnul(fmt, '%');
		written += write(1, fmt, next - fmt);
		if (*next)
		{
			a = write_spec(ap, *(++next));
			if (a < 0)
				return (-1);
			written += a;
			fmt = ++next;
		}
	}
	return (written);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		ret;

	if (fmt == NULL)
		return (-1);
	va_start(ap, fmt);
	ret = ft_vprintf(fmt, ap);
	va_end(ap);
	return (ret);
}

#include <assert.h>
#include <limits.h>

int	main(void)
{
	ft_printf("%C %C %C", 'a', 'b', 'c');
	return (0);
}
// 	int	a;
// 	int	x;
//
// 	int ret1, ret2;
// 	printf("--- Testing Characters and Strings ---\n");
// 	ret1 = ft_printf("Mine: %c | %s | %%\n", 'A', "Hello World");
// 	ret2 = printf("Real: %c | %s | %%\n", 'A', "Hello World");
// 	printf("Lengths: mine=%d, real=%d\n\n", ret1, ret2);
// 	printf("--- Testing Integers ---\n");
// 	ret1 = ft_printf("Mine: %d | %i | %u\n", -123, 456, 4294967295U);
// 	ret2 = printf("Real: %d | %i | %u\n", -123, 456, 4294967295U);
// 	printf("Lengths: mine=%d, real=%d\n\n", ret1, ret2);
// 	printf("--- Testing Hex (Lower and Upper) ---\n");
// 	ret1 = ft_printf("Mine: %x | %X\n", 255, 255);
// 	ret2 = printf("Real: %x | %X\n", 255, 255);
// 	printf("Lengths: mine=%d, real=%d\n\n", ret1, ret2);
// 	printf("--- Testing Pointers ---\n");
// 	a = 42;
// 	ret1 = ft_printf("Mine: %p | %p\n", &a, NULL);
// 	ret2 = printf("Real: %p | %p\n", &a, NULL);
// 	printf("Lengths: mine=%d, real=%d\n\n", ret1, ret2);
// 	printf("--- Testing Edge Cases ---\n");
// 	ft_printf("Mine NULL string: %s\n", (char *)NULL);
// 	printf("Real NULL string: %s\n", (char *)NULL);
// 	// 1. Min/Max Integers
// 	printf("REAL: %d, %d\n", INT_MIN, INT_MAX);
// 	ft_printf("MINE: %d, %d\n\n", INT_MIN, INT_MAX);
// 	// 2. Unsigned Wrap
// 	printf("REAL: %u\n", (unsigned int)-1);
// 	ft_printf("MINE: %u\n\n", (unsigned int)-1);
// 	// 3. Pointer addresses
// 	x = 0;
// 	printf("REAL: %p\n", &x);
// 	ft_printf("MINE: %p\n\n", &x);
// 	// 4. Mixing types
// 	printf("REAL: %c %s %x %%\n", 'G', "Gemini", 42);
// 	ft_printf("MINE: %c %s %x %%\n\n", 'G', "Gemini", 42);
// 	return (0);
// }
