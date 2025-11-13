#include "util.h"
#include <stdlib.h>

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

char	*ft_strchrnul(const char *s, int c)
{
	while (*s && *s != (char)c)
		s++;
	return ((char *)s);
}

static char	*rev_str(const char *src, int len)
{
	int		i;
	char	*str;

	str = malloc(len + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (len > 0)
		str[i++] = src[--len];
	str[i] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	char			buf[16];
	unsigned int	un;
	int				i;

	i = 0;
	if (n < 0)
		un = -n;
	else
		un = n;
	if (un == 0)
		buf[i++] = '0';
	else
	{
		while (un)
		{
			buf[i++] = '0' + (un % 10);
			un /= 10;
		}
	}
	if (n < 0)
		buf[i++] = '-';
	return (rev_str(buf, i));
}

static int	ft_isspace(int c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}

int	ft_atoi(const char *nptr)
{
	int	a;
	int	neg;

	while (ft_isspace(*nptr))
		nptr++;
	neg = 0;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			neg = 1;
		nptr++;
	}
	a = 0;
	while (ft_isdigit(*nptr))
	{
		a *= 10;
		a += *nptr - '0';
		nptr++;
	}
	if (neg)
		return (-a);
	return (a);
}



char	*ultostr(size_t n, char *base, int base_len)
{
	int		i;
	char	buf[65];
	char	*str;
	int		j;

	i = 0;
	if (n == 0)
		buf[i++] = base[0];
	while (n)
	{
		buf[i++] = base[n % base_len];
		n /= base_len;
	}
	str = malloc(i + 1);
	if (!str)
		return (NULL);
	str[i] = '\0';
	j = 0;
	while (i)
		str[j++] = buf[--i];
	return (str);
}

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = c;
		i++;
	}
	return (s);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
