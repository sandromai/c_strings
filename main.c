#include <stdlib.h>
#include <stdio.h>

#define bool unsigned int
#define true 1
#define false 0

#define TRIM_LEFT -1
#define TRIM_BOTH 0
#define TRIM_RIGHT 1

#define PAD_LEFT -1
#define PAD_BOTH 0
#define PAD_RIGHT 1

unsigned int str_length(const char *str) {
  unsigned int length = 0;

  while (*str++) {
    ++length;
  }

  return length;
}

bool str_compare(const char *str1, const char *str2) {
  bool result = true;

  for (unsigned int i = 0; (*(str1 + i) != '\0') || (*(str2 + i) != '\0'); ++i) {
    if (*(str1 + i) != *(str2 + i)) {
      result = false;
      break;
    }
  }

  return result;
}

bool str_starts_with(const char *str, const char *start) {
  bool result = true;

  for (unsigned int i = 0; *(start + i) != '\0'; ++i) {
    if (*(start + i) != *(str + i)) {
      result = false;
      break;
    }
  }

  return result;
}

bool str_ends_with(const char *str, const char *end) {
  bool result = false;
  unsigned int start = 0;

  for (unsigned int i = 0; *(str + i) != '\0'; ++i) {
    if (result) {
      if (*(str + i) != *(end + start)) {
        result = false;
        start = 0;
      } else {
        ++start;
      }
    } else if (*(str + i) == *end) {
      result = true;
      ++start;
    }
  }

  if (result && *(end + start) != '\0') {
    result = false;
  }

  return result;
}

char *str_concat(const char *str1, const char *str2) {
  char *result = malloc((str_length(str1) + str_length(str2)) * sizeof(char));

  for (unsigned int i = 0; 1 == 1; ++i) {
    if (*str1 != '\0') {
      *(result + i) = *str1;
      *str1++;
    } else if (*str2 != '\0') {
      *(result + i) = *str2;
      *str2++;
    } else {
      *(result + i) = '\0';
      break;
    }
  }

  return result;
}

char *str_to_upper(const char *str) {}

char *str_to_lower(const char *str) {}

char *str_reverse(const char *str) {
  unsigned int length = str_length(str);
  char *result = (char *)malloc((length * sizeof(char)) + 1);

  unsigned int i = 0;

  while (length--) {
    *(result + i) = *(str + length);
    ++i;
  }

  *(result + i) = '\0';

  return result;
}

char *str_trim(const char *str, int side) {}

char *str_pad(
  const char *str,
  unsigned int length,
  const char *pad_str,
  int side
) {}

char *str_replace(
  const char *search,
  const char *replace,
  const char *subject,
  unsigned int count
) {}

char **str_split(char *str, const char *separator) {}

char **str_split_n(
  const char *str,
  const char *separator,
  unsigned int n
) {}

char *str_join(const char **str, const char *separator) {}

int str_to_int(const char *str) {
  bool negative = false;

  if (*str == '-') {
    negative = true;
    *str++;
  } else if (*str == '+') {
    *str++;
  }

  int result = 0;
  bool unexpected = false;

  while (*str != '\0' && !unexpected) {
    switch (*str) {
      case '0':
        result *= 10;
        break;

      case '1':
        result = (result * 10) + 1;
        break;

      case '2':
        result = (result * 10) + 2;
        break;

      case '3':
        result = (result * 10) + 3;
        break;

      case '4':
        result = (result * 10) + 4;
        break;

      case '5':
        result = (result * 10) + 5;
        break;

      case '6':
        result = (result * 10) + 6;
        break;

      case '7':
        result = (result * 10) + 7;
        break;

      case '8':
        result = (result * 10) + 8;
        break;

      case '9':
        result = (result * 10) + 9;
        break;

      default:
        unexpected = true;
        break;
    }

    *str++;
  }

  if (negative) {
    result = -result;
  }

  return result;
}

float str_to_float(const char *str) {
  bool negative = false;

  if (*str == '-') {
    negative = true;
    *str++;
  } else if (*str == '+') {
    *str++;
  }

  unsigned int whole_part = 0;
  float decimal_part = 0;
  unsigned int decimal_point = 0;
  unsigned int decimal_count = 0;
  bool unexpected = false;

  while (*str != '\0' && !unexpected) {
    if (decimal_point == 1) {
      ++decimal_count;
    }

    switch (*str) {
      case '.':
        decimal_point = 1;
        break;

      case '0':
        if (decimal_point == 0) {
          whole_part *= 10;
        } else {
          decimal_part *= 10;
        }

        break;

      case '1':
        if (decimal_point == 0) {
          whole_part = (whole_part * 10) + 1;
        } else {
          decimal_part = (decimal_part * 10) + 1;
        }

        break;

      case '2':
        if (decimal_point == 0) {
          whole_part = (whole_part * 10) + 2;
        } else {
          decimal_part = (decimal_part * 10) + 2;
        }

        break;

      case '3':
        if (decimal_point == 0) {
          whole_part = (whole_part * 10) + 3;
        } else {
          decimal_part = (decimal_part * 10) + 3;
        }

        break;

      case '4':
        if (decimal_point == 0) {
          whole_part = (whole_part * 10) + 4;
        } else {
          decimal_part = (decimal_part * 10) + 4;
        }

        break;

      case '5':
        if (decimal_point == 0) {
          whole_part = (whole_part * 10) + 5;
        } else {
          decimal_part = (decimal_part * 10) + 5;
        }

        break;

      case '6':
        if (decimal_point == 0) {
          whole_part = (whole_part * 10) + 6;
        } else {
          decimal_part = (decimal_part * 10) + 6;
        }

        break;

      case '7':
        if (decimal_point == 0) {
          whole_part = (whole_part * 10) + 7;
        } else {
          decimal_part = (decimal_part * 10) + 7;
        }

        break;

      case '8':
        if (decimal_point == 0) {
          whole_part = (whole_part * 10) + 8;
        } else {
          decimal_part = (decimal_part * 10) + 8;
        }

        break;

      case '9':
        if (decimal_point == 0) {
          whole_part = (whole_part * 10) + 9;
        } else {
          decimal_part = (decimal_part * 10) + 9;
        }

        break;

      default:
        unexpected = true;

        if (decimal_count > 0) {
          --decimal_count;
        }

        break;
    }

    *str++;
  }

  for (; decimal_count > 0; --decimal_count) {
    decimal_part *= 0.1;
  }

  float result = whole_part + decimal_part;

  if (negative) {
    result = -result;
  }

  return result;
}

int main(void) {
  char *my_str = "Hello world!";
  char *my_str_2 = "Hello world!";

  printf("%s\n", my_str);
  printf("%s\n", str_reverse(my_str));

  return 0;
}