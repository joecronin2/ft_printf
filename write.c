#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>

#include "util.h"

int
write_num (long long n, char *base, char *prefix)
{
  char buf[64];
  int len = 0;
  int base_len = ft_strlen (base);
  if (prefix) len += write (1, prefix, ft_strlen (prefix));
  int num_len = ft_putnbr_base (buf, n, base, base_len);
  len += write (1, buf, num_len);
  return len;
}

int
write_str (char *s)
{
  if (!s) return write (1, "(null)", 6);
  size_t len = ft_strlen (s);
  return write (1, s, len);
}

int
write_char (char c)
{
  return write (1, &c, 1);
}

int
write_ptr (void *ptr)
{
  if (!ptr) return write (1, "(nil)", 5);
  int len = write_num ((long long)ptr, "0123456789abcdef", "0x");
  return len;
}

int
write_spec (va_list ap, char spec)
{
  if (spec == 'd' || spec == 'i')
    return write_num (va_arg (ap, int), "0123456789", "");
  else if (spec == 'u')
    return write_num (va_arg (ap, unsigned int), "0123456789", "");
  else if (spec == 'x')
    return write_num (va_arg (ap, unsigned int), "0123456789abcdef", "");
  else if (spec == 'X')
    return write_num (va_arg (ap, unsigned int), "0123456789ABCDEF", "");
  else if (spec == 'p')
    return write_ptr (va_arg (ap, void *));
  else if (spec == 's')
    return write_str (va_arg (ap, char *));
  else if (spec == 'c')
    return write_char (va_arg (ap, int));
  else if (spec == '%')
    return write (1, "%", 1);
  return -1;
}
