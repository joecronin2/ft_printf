#pragma once
#include <stdbool.h>

typedef struct s_fmt
{
  int width;
  int precision;   // '.8'
  bool left_align; // '-'
  bool space;      // ' '
  bool zero;       // '0'
  bool plus;       // '+'
  bool alt;        // '#'
  char spec;
} t_fmt;

const char *parse_fmt (const char *s, t_fmt *fmt);
