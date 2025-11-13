#include <ctype.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "format.h"
#include "util.h"
#include "write.h"

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

int
_vprintf (const char *fmt, va_list ap)
{
  t_fmt f;
  char *next;
  int written;

  written = 0;
  memset (&f, 0, sizeof (f));
  while (*fmt)
    {
      next = ft_strchrnul (fmt, '%');
      write (1, fmt, next - fmt);
      written += next - fmt;
      fmt = next;
      if (*fmt)
        {
          fmt = parse_fmt (fmt, &f);
          written += write_spec (ap, &f);
        }
    }
  return (written);
}

// if NULL return -1

int
_printf (const char *fmt, ...)
{
  va_list ap;
  int ret;

  va_start (ap, fmt);
  ret = _vprintf (fmt, ap);
  va_end (ap);
  return (ret);
}

void
print_fmt (t_fmt *fmt)
{
  printf ("width: %d\n", fmt->width);
  printf ("left align: %s\n", fmt->left_align ? "true" : "false");
  printf ("space: %s\n", fmt->space ? "true" : "false");
  printf ("zero: %s\n", fmt->zero ? "true" : "false");
  printf ("plus: %s\n", fmt->plus ? "true" : "false");
  printf ("alt: %s\n", fmt->alt ? "true" : "false");
  printf ("spec: %c\n", fmt->spec);
}

#include <assert.h>

void
test_parse (void)
{
  t_fmt f;

  memset (&f, 0, sizeof (f));
  // all options
  parse_fmt ("%- 0+#10d", &f);
  assert (f.left_align == true);
  assert (f.space == true);
  assert (f.zero == true);
  assert (f.plus == true);
  assert (f.alt == true);
  assert (f.width == 10);
  assert (f.spec == 'd');
  memset (&f, 0, sizeof (f));
  // optional flags
  parse_fmt ("%10d", &f);
  assert (f.left_align == false);
  assert (f.space == false);
  assert (f.zero == false);
  assert (f.plus == false);
  assert (f.alt == false);
  assert (f.width == 10);
  assert (f.spec == 'd');
  memset (&f, 0, sizeof (f));
  // optional width
  f.width = 0;
  parse_fmt ("%- 0+#d", &f);
  assert (f.left_align == true);
  assert (f.space == true);
  assert (f.zero == true);
  assert (f.plus == true);
  assert (f.alt == true);
  assert (f.width == 0);
  assert (f.spec == 'd');
}

void
test_decimal ()
{
  int nums[] = { 0, 1, -1, 42, -42, 1234, -1234, 999999, -999999 };

  for (int i = 0; i < (int)(sizeof (nums) / sizeof (nums[0])); i++)
    {
      int n = nums[i];

      printf ("basic number\n|%d|\n", n);
      _printf ("|%d|\n", n);

      printf ("sign flag\n|%+d|\n", n);
      _printf ("|%+d|\n", n);

      printf ("width\n|%6d|\n", n);
      _printf ("|%6d|\n", n);

      printf ("width + sign\n|%+6d|\n", n);
      _printf ("|%+6d|\n", n);

      printf ("zero-padding\n|%06d|\n", n);
      _printf ("|%06d|\n", n);

      printf ("zero-padding + sign\n|%+06d|\n", n);
      _printf ("|%+06d|\n", n);

      printf ("left-align\n|%-6d|\n", n);
      _printf ("|%-6d|\n", n);

      printf ("precision only\n|%.4d|\n", n);
      _printf ("|%.4d|\n", n);

      printf ("precision + width\n|%8.4d|\n", n);
      _printf ("|%8.4d|\n", n);

      printf ("left-align + precision + width\n|%-8.4d|\n", n);
      _printf ("|%-8.4d|\n", n);

      printf ("----------\n");
    }
}

void
test_str ()
{
	_printf("...%s...", "testabc");
}

int
main (void)
{
	int r = _printf("%", 123);
  // test_str ();
  return 0;
}

// int
// main (void)
// {
//   test_parse ();
//   // _printf("|%.10d| |-123|\n", -1234);
//   printf ("|%.6d|\n", -1234);
//   printf ("|%06d|\n", -1234);
//   printf ("|%02d|\n", -1234);
//   _printf ("%d\n", 1234);
//   _printf ("%+d\n", 1234);
//   _printf ("%010d\n", -1234);
//   _printf ("%+010d\n", 1234);
//   _printf ("%+10d\n", 1234);
//   _printf ("%-10d\n", -1234);
//   _printf ("abc %c %c %c\n", '1', '2', '3');
//   return (0);
// }
