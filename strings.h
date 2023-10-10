#ifndef _STRINGS_H

#define _STRINGS_H

#include <stdlib.h>

#include "libs/c_bool/bool.h"

#ifndef TRIM_CHARS
#define TRIM_CHARS " \n\r\t\v"
#endif

#ifndef TRIM_LEFT
#define TRIM_LEFT -1
#endif

#ifndef TRIM_BOTH
#define TRIM_BOTH 0
#endif

#ifndef TRIM_RIGHT
#define TRIM_RIGHT 1
#endif

#ifndef PAD_STR
#define PAD_STR " "
#endif

#ifndef PAD_LEFT
#define PAD_LEFT -1
#endif

#ifndef PAD_BOTH
#define PAD_BOTH 0
#endif

#ifndef PAD_RIGHT
#define PAD_RIGHT 1
#endif

unsigned int str_length(const char *str);

bool str_compare(const char *str1, const char *str2);

bool str_contains(const char *str, const char *search);

bool str_starts_with(const char *str, const char *start);

bool str_ends_with(const char *str, const char *end);

char *str_concat(const char *str1, const char *str2);

char *str_copy(const char *str);

char *str_to_upper(const char *str);

char *str_to_lower(const char *str);

char *str_capitalize(
  const char *str,
  const char *separators,
  const unsigned int count
);

char *str_reverse(const char *str);

char *str_part(
  const char *str,
  const unsigned int start,
  const unsigned int length
);

char *str_trim(
  const char *str,
  const char *chars,
  int side
);

char *str_pad(
  const char *str,
  unsigned int length,
  const char *pad_str,
  int side
);

char *str_replace(
  const char *str,
  const char *search,
  const char *replace,
  unsigned int count
);

char **str_split(const char *str, const char *separator);

char **str_split_n(
  const char *str,
  const char *separator,
  unsigned int n
);

char *str_join(char **array, const char *separator);

int str_to_int(const char *str);

float str_to_float(const char *str);

char *int_to_str(int number);

#endif /* strings.h  */
