#include "format.h"
#include "util.h"

bool
is_flag (char c)
{
  return (c == '-' || c == ' ' || c == '0' || c == '+' || c == '#');
}

void
set_flag (char c, t_fmt *fmt)
{
  if (c == '-') fmt->left_align = true;
  if (c == ' ') fmt->space = true;
  if (c == '0') fmt->zero = true;
  if (c == '+') fmt->plus = true;
  if (c == '#') fmt->alt = true;
}

// _printf("%+010d\n", 1234);
// % [flags] [width] .[precision] specifier
const char *
parse_fmt (const char *s, t_fmt *fmt)
{
  s++;
  while (is_flag (*s))
    set_flag (*s++, fmt);
  if (ft_isdigit (*s))
    {
      fmt->width = ft_atoi (s);
      while (ft_isdigit (*s))
        s++;
    }
  if (*s == '.')
    {
      fmt->precision = ft_atoi (++s);
      while (ft_isdigit (*s))
        s++;
    }
  fmt->spec = *s++;
  return (s);
}
