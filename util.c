#include "util.h"
#include <stdlib.h>

char *
ft_strchrnul (const char *s, int c)
{
  while (*s && *s != (char)c)
    s++;
  return ((char *)s);
}

size_t
ft_strlen (const char *s)
{
  const char *i = s;
  while (*i)
    i++;
  return (i - s);
}

static void
swap_char (char *a, char *b)
{
  char tmp = *a;
  *a = *b;
  *b = tmp;
}

static void
rev_str (char *s, size_t len)
{
  size_t i = 0;
  size_t j = len - 1;
  while (i < j)
    swap_char (&s[i++], &s[j--]);
}

int
ft_putnbr_base (char buf[], long long n, char *base_str, int base_len)
{
  int i = 0;
  unsigned long long nb;
  if (n < 0 && base_len == 10)
    {
      buf[i++] = '-';
      nb = -n;
    }
  else
    nb = (unsigned long long)n;
  int start = i;
  if (nb == 0)
    buf[i++] = base_str[0];
  else
    {
      while (nb != 0)
        {
          buf[i++] = base_str[nb % base_len];
          nb /= base_len;
        }
    }
  buf[i] = '\0';
  rev_str (buf + start, i - start);
  return i;
}
