#include <stdarg.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

#include "util.h"
#include "write.h"

int
calc_padding (int width, int len)
{
  if (width) return (width - len);
  return (0);
}

int
write_sign (bool negative, bool plus)
{
  int written;

  written = 0;
  if (negative)
    write (1, "-", ++written);
  else if (plus)
    write (1, "+", ++written);
  return (written);
}

int
write_pad (bool zero, int pad)
{
  char *buf;

  buf = malloc (pad);
  if (zero)
    ft_memset (buf, '0', pad);
  else
    ft_memset (buf, ' ', pad);
  write (1, buf, pad);
  free (buf);
  return pad;
}

int
write_decimal (t_fmt *fmt, va_list ap)
{
  char *str;
  bool negative;
  int pad;
  int len;
  int written;

  int n = va_arg (ap, int);
  negative = n < 0;
  if (negative) n = -n;

  written = 0;
  str = ft_itoa (n);
  len = ft_strlen (str);
  pad = calc_padding (fmt->width, len);
  if (fmt->zero)
    {
      // always right, sign padding num
      written += write_sign (negative, fmt->plus);
      write_pad (fmt->zero, pad);
      write (1, str, len);
    }
  else if (fmt->left_align)
    {
      // always left, sign num padding
      written += write_sign (negative, fmt->plus);
      write (1, str, len);
      write_pad (0, pad);
    }
  else
    {
      // always right, padding sign num
      write_pad (fmt->zero, pad);
      written += write_sign (negative, fmt->plus);
      write (1, str, len);
    }
  free (str);
  return (written);
}

int
write_str (t_fmt *fmt, va_list ap)
{
  int slen;
  int pad;
  char *s = va_arg (ap, char *);
  int written = 0;

  slen = ft_strlen (s);
  pad = fmt->width ? fmt->width - slen : 0;
  if (!fmt->left_align) write_pad (0, pad);
  write (1, s, slen);
  if (fmt->left_align) write_pad (0, pad);
  return written;
}

int
write_char (t_fmt *fmt, va_list ap)
{
  (void)fmt; // TODO
  char c = va_arg (ap, int);
  write (1, &c, 1);
  return 1;
}

int
write_spec (va_list ap, t_fmt *fmt)
{
  if (fmt->spec == 'd')
    return write_decimal (fmt, ap);
  else if (fmt->spec == 's')
    return write_str (fmt, ap);
  else if (fmt->spec == 'c')
    return write_char (fmt, ap);
  return 0;
}
