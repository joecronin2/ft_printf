#include "libft.h"

char	*ft_lltostr_base(long long n, char *base, int base_len)
{
	char				buf[22];
	unsigned long long	un;
	int					i;

	if (n < 0)
		un = -n;
	else
		un = n;
	i = 0;
	if (un == 0)
		buf[i++] = '0';
	else
	{
		while (un)
		{
			buf[i++] = base[un % base_len];
			un /= base_len;
		}
	}
	buf[i] = '\0';
	if (n < 0)
		buf[i++] = '-';
	buf[i] = '\0';
	return (ft_strrev(buf));
}

char	*ft_lltostr(long long n)
{
	return (ft_lltostr_base(n, "0123456789", 10));
}

char	*ft_itostr_base(int n, char *base, int base_len)
{
	return (ft_lltostr_base(n, base, base_len));
}

char	*ft_itostr(int n)
{
	return (ft_itostr_base(n, "0123456789", 10));
}

#include <assert.h>
#include <string.h>

int	main(void)
{
	assert(strcmp(ft_lltostr(0), "0") == 0);
	assert(strcmp(ft_lltostr(9223372036854775807), "9223372036854775807") == 0);
	assert(strcmp(ft_lltostr(-9223372036854775807),
			"-9223372036854775807") == 0);
	return (0);
}
