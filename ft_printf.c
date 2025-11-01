#include <ctype.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct s_fmt
{
	int		width;
	int precision;   // '.8'
	bool left_align; // '-'
	bool space;      // ' '
	bool zero;       // '0'
	bool plus;       // '+'
	bool alt;        // '#'
	char	spec;
}			t_fmt;

bool	is_flag(char c)
{
	return (c == '-' || c == ' ' || c == '0' || c == '+' || c == '#');
}

void	set_flag(char c, t_fmt *fmt)
{
	if (c == '-')
		fmt->left_align = true;
	if (c == ' ')
		fmt->space = true;
	if (c == '0')
		fmt->zero = true;
	if (c == '+')
		fmt->plus = true;
	if (c == '#')
		fmt->alt = true;
}

	// _printf("%+010d\n", 1234);
// % [flags] [width] .[precision] specifier
const char	*parse_fmt(const char *s, t_fmt *fmt)
{
	s++;
	while (is_flag(*s))
		set_flag(*s++, fmt);
	if (isdigit(*s))
	{
		fmt->width = atoi(s);
		while (isdigit(*s))
			s++;
	}
	if (*s == '.')
	{
		fmt->precision = atoi(++s);
		while (isdigit(*s))
			s++;
	}
	fmt->spec = *s++;
	return (s);
}

char	*ft_strchrnul(const char *s, int c)
{
	while (*s && *s != (char)c)
		s++;
	return ((char *)s);
}

void	write_pad(bool zero, int pad)
{
	char	*buf;

	buf = malloc(pad);
	if (zero)
		memset(buf, '0', pad);
	else
		memset(buf, ' ', pad);
	write(1, buf, pad);
	free(buf);
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
	buf[i] = '\0';
	if (n < 0)
		buf[i++] = '-';
	return (rev_str(buf, i));
}

// 00001234 0
// -0001234 0
// +0001234 +0
// -0001234 +0
// -1234    l
// +1234    +l
//    -1234
//    +1234 +
//
// structure zeros (zeros disables left): sign padding num (no padding)
// 00001234
// -0001234
// +0001234
// -0001234

// structure left (no zeros): sign num padding
// -1234     |
// +1234     |
// +1234     |
//
// structure spaces (left handled): padding sign num
//      -1234|

int	calc_padding(int width, int len)
{
	if (width)
		return (width - len);
	return (0);
}

int	write_sign(bool negative, bool plus)
{
	int	written;

	written = 0;
	if (negative)
		write(1, "-", ++written);
	else if (plus)
		write(1, "+", ++written);
	return (written);
}

int	write_decimal(t_fmt *fmt, int d)
{
	char	*str;
	bool	negative;
	int		pad;
	int		len;
	int		written;

	written = 0;
	if (d < 0)
	{
		negative = true;
		d = -d;
	}
	else
		negative = false;
	str = ft_itoa(d);
	len = strlen(str);
	if (fmt->precision > len)
		pad = calc_padding(fmt->precision, len);
	else
		pad = calc_padding(fmt->width, len);
	if (fmt->zero)
	{
		// always right, sign padding num
		written += write_sign(negative, fmt->plus);
		write_pad(fmt->zero, pad);
		write(1, str, len);
	}
	else if (fmt->left_align)
	{
		// always left, sign num padding
		written += write_sign(negative, fmt->plus);
		write(1, str, len);
		write_pad(0, pad);
	}
	else
	{
		// always right, padding sign num
		write_pad(fmt->zero, pad);
		written += write_sign(negative, fmt->plus);
		write(1, str, len);
	}
	free(str);
	return (written);
}

void	write_str(t_fmt *fmt, char *s)
{
	int	slen;
	int	pad;

	slen = strlen(s);
	pad = fmt->width ? fmt->width - slen : 0;
	if (!fmt->left_align)
		write_pad(0, pad);
	write(1, s, slen);
	if (fmt->left_align)
		write_pad(0, pad);
}

int	_vprintf(const char *fmt, va_list ap)
{
	t_fmt	f;
	int		i;
	char	c;
	char	*next;
	int		written;

	written = 0;
	// TODO: unsigned?
	memset(&f, 0, sizeof(f));
	while (*fmt)
	{
		next = ft_strchrnul(fmt, '%');
		write(1, fmt, next - fmt);
		written += next - fmt;
		fmt = next;
		if (*fmt)
		{
			fmt = parse_fmt(fmt, &f);
			if (f.spec == 'd')
			{
				i = va_arg(ap, int);
				written += write_decimal(&f, i);
			}
			// else if (f.spec == 's'){
			// 	c = va_arg(ap, char);
			// 	write_str(1, &c, 1);
			// }
			else if (f.spec == 'c')
			{
				c = va_arg(ap, int);
				write(1, &c, 1);
			}
		}
	}
	return (written); // TODO
}

int	_printf(const char *fmt, ...)
{
	va_list	ap;
	int		ret;

	va_start(ap, fmt);
	ret = _vprintf(fmt, ap);
	va_end(ap);
	return (ret);
}

void	print_fmt(t_fmt *fmt)
{
	printf("width: %d\n", fmt->width);
	printf("left align: %s\n", fmt->left_align ? "true" : "false");
	printf("space: %s\n", fmt->space ? "true" : "false");
	printf("zero: %s\n", fmt->zero ? "true" : "false");
	printf("plus: %s\n", fmt->plus ? "true" : "false");
	printf("alt: %s\n", fmt->alt ? "true" : "false");
	printf("spec: %c\n", fmt->spec);
}

#include <assert.h>

void	test_parse(void)
{
	t_fmt	f;

	memset(&f, 0, sizeof(f));
	// all options
	parse_fmt("%- 0+#10d", &f);
	assert(f.left_align == true);
	assert(f.space == true);
	assert(f.zero == true);
	assert(f.plus == true);
	assert(f.alt == true);
	assert(f.width == 10);
	assert(f.spec == 'd');
	memset(&f, 0, sizeof(f));
	// optional flags
	parse_fmt("%10d", &f);
	assert(f.left_align == false);
	assert(f.space == false);
	assert(f.zero == false);
	assert(f.plus == false);
	assert(f.alt == false);
	assert(f.width == 10);
	assert(f.spec == 'd');
	memset(&f, 0, sizeof(f));
	// optional width
	f.width = 0;
	parse_fmt("%- 0+#d", &f);
	assert(f.left_align == true);
	assert(f.space == true);
	assert(f.zero == true);
	assert(f.plus == true);
	assert(f.alt == true);
	assert(f.width == 0);
	assert(f.spec == 'd');
}

int	main(void)
{
	test_parse();
	_printf("|%.10d| |-123|\n", -1234);
	printf("|%.10d| |-123|\n", -1234);
	_printf("%d\n", 1234);
	_printf("%+d\n", 1234);
	_printf("%+d\n", -1234);
	_printf("%010d\n", -1234);
	_printf("%+010d\n", 1234);
	_printf("%+10d\n", 1234);
	_printf("%-10d\n", -1234);
	_printf("abc %c %c %c\n", '1', '2', '3');
	return (0);
}
