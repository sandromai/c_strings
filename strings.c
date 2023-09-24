#include <stdlib.h>

#define bool unsigned int
#define true 1
#define false 0

#define TRIM_CHARS " \n\r\t\v"
#define TRIM_LEFT -1
#define TRIM_BOTH 0
#define TRIM_RIGHT 1

#define PAD_STR " "
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

  for (unsigned int i = 0; *(str1 + i) || *(str2 + i); ++i) {
    if (*(str1 + i) != *(str2 + i)) {
      result = false;
      break;
    }
  }

  return result;
}

bool str_contains(const char *str, const char *search) {
  if (!*search) {
    return true;
  }

  bool result = false;
  unsigned int found_index = 0;

  for (unsigned int i = 0; *(str + i) || *(search + i - found_index); ++i) {
    if (!*(str + i)) {
      result = false;
      break;
    }

    if (result) {
      if (!*(search + i - found_index)) {
        break;
      }

      if (*(str + i) != *(search + i - found_index)) {
        result = false;
      }
    } else if (*(str + i) == *search) {
      result = true;
      found_index = i;
    }
  }

  return result;
}

bool str_starts_with(const char *str, const char *start) {
  bool result = true;

  for (unsigned int i = 0; *(start + i); ++i) {
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

  for (unsigned int i = 0; *(str + i); ++i) {
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

  if (result && *(end + start)) {
    result = false;
  }

  return result;
}

char *str_concat(const char *str1, const char *str2) {
  char *result = malloc((str_length(str1) + str_length(str2) + 1) * sizeof *result);

  if (result == NULL) {
    return NULL;
  }

  for (unsigned int i = 0; true; ++i) {
    if (*str1) {
      *(result + i) = *str1;
      str1++;
    } else if (*str2) {
      *(result + i) = *str2;
      str2++;
    } else {
      *(result + i) = '\0';
      break;
    }
  }

  return result;
}

char *str_copy(const char *str) {
  char *result = malloc((str_length(str) + 1) * sizeof *result);

  if (result == NULL) {
    return NULL;
  }

  unsigned int i = 0;

  for (; *(str + i); ++i) {
    *(result + i) = *(str + i);
  }

  *(result + i) = '\0';

  return result;
}

char *str_to_upper(const char *str) {
  char *result = malloc((str_length(str) + 1) * sizeof *result);

  if (result == NULL) {
    return NULL;
  }

  for (unsigned int i = 0; *(str + i); ++i) {
    if (*(str + i) >= 97 && *(str + i) <= 122) {
      *(result + i) = *(str + i) - 32;
    } else {
      *(result + i) = *(str + i);
    }
  }

  return result;
}

char *str_to_lower(const char *str) {
  char *result = malloc((str_length(str) + 1) * sizeof *result);

  if (result == NULL) {
    return NULL;
  }

  for (unsigned int i = 0; *(str + i); ++i) {
    if (*(str + i) >= 65 && *(str + i) <= 90) {
      *(result + i) = *(str + i) + 32;
    } else {
      *(result + i) = *(str + i);
    }
  }

  return result;
}

char *str_capitalize(
  const char *str,
  const char *separators,
  const unsigned int count
) {
  char *result = malloc((str_length(str) + 1) * sizeof *result);

  if (result == NULL) {
    return NULL;
  }

  char *current_str = malloc(2 * sizeof *current_str);

  if (current_str == NULL) {
    free(result);
    result = NULL;
    return NULL;
  }

  bool capitalize = true;
  unsigned int capitalizations_count = 0;

  for (unsigned int i = 0; *(str + i); ++i) {
    if (capitalize) {
      if (*(str + i) >= 97 && *(str + i) <= 122) {
        *(result + i) = *(str + i) - 32;
      } else {
        *(result + i) = *(str + i);
      }

      capitalize = false;
      ++capitalizations_count;
    } else {
      *current_str = *(str + i);
      *(current_str + 1) = '\0';

      if ((count == 0 || capitalizations_count < count) && str_contains(separators, current_str)) {
        capitalize = true;
      }

      *(result + i) = *(str + i);
    }
  }

  free(current_str);
  current_str = NULL;

  return result;
}

char *str_reverse(const char *str) {
  unsigned int length = str_length(str);
  char *result = malloc((length + 1) * sizeof *result);

  if (result == NULL) {
    return NULL;
  }

  unsigned int i = 0;

  while (length--) {
    *(result + i) = *(str + length);
    ++i;
  }

  *(result + i) = '\0';

  return result;
}

char *str_part(
  const char *str,
  const unsigned int start,
  const unsigned int length
) {
  int size;

  if (length) {
    size = length + 1;
  } else {
    size = str_length(str) + 1 - start;
  }

  if (size <= 0) {
    return "";
  }

  char *result = malloc(size * sizeof *result);

  if (result == NULL) {
    return NULL;
  }

  unsigned int i = 0;

  for (; (length == 0 || i < length) && *(str + start + i); ++i) {
    *(result + i) = *(str + start + i);
  }

  *(result + i) = '\0';

  return result;
}

char *str_trim(
  const char *str,
  const char *chars,
  int side
) {
  unsigned int length = str_length(str);
  char *result = malloc((length + 1) * sizeof *result);

  if (result == NULL) {
    return NULL;
  }

  char *current_str = malloc(2 * sizeof *current_str);

  if (current_str == NULL) {
    free(result);
    result = NULL;
    return NULL;
  }

  bool trim = true;
  unsigned int j = 0;

  if (side == TRIM_LEFT) {
    for (unsigned int i = 0; *(str + i); ++i) {
      if (trim) {
        *current_str = *(str + i);
        *(current_str + 1) = '\0';

        if (!str_contains(chars, current_str)) {
          trim = false;
          *(result + j) = *(str + i);
          ++j;
        }
      } else {
        *(result + j) = *(str + i);
        ++j;
      }
    }

    *(result + j) = '\0';
  } else if (side == TRIM_RIGHT) {
    char *reversed_str = str_reverse(str);

    if (reversed_str == NULL) {
      free(result);
      result = NULL;
      free(current_str);
      current_str = NULL;
      return NULL;
    }

    for (unsigned int i = 0; *(reversed_str + i); ++i) {
      if (trim) {
        *current_str = *(reversed_str + i);
        *(current_str + 1) = '\0';

        if (!str_contains(chars, current_str)) {
          trim = false;
          *(result + j) = *(reversed_str + i);
          ++j;
        }
      } else {
        *(result + j) = *(reversed_str + i);
        ++j;
      }
    }

    free(reversed_str);
    reversed_str = NULL;

    *(result + j) = '\0';

    result = str_reverse(result);

    if (result == NULL) {
      free(current_str);
      current_str = NULL;
      return NULL;
    }
  } else {
    for (unsigned int i = 0; *(str + i); ++i) {
      if (trim) {
        *current_str = *(str + i);
        *(current_str + 1) = '\0';

        if (!str_contains(chars, current_str)) {
          trim = false;
          *(result + j) = *(str + i);
          ++j;
        }
      } else {
        *(result + j) = *(str + i);
        ++j;
      }
    }

    *(result + j) = '\0';

    char *reversed_str = str_reverse(result);

    if (reversed_str == NULL) {
      free(result);
      result = NULL;
      free(current_str);
      current_str = NULL;
      return NULL;
    }

    trim = true;
    j = 0;

    for (unsigned int i = 0; *(reversed_str + i); ++i) {
      if (trim) {
        *current_str = *(reversed_str + i);
        *(current_str + 1) = '\0';

        if (!str_contains(chars, current_str)) {
          trim = false;
          *(result + j) = *(reversed_str + i);
          ++j;
        }
      } else {
        *(result + j) = *(reversed_str + i);
        ++j;
      }
    }

    free(reversed_str);
    reversed_str = NULL;

    *(result + j) = '\0';

    result = str_reverse(result);

    if (result == NULL) {
      free(current_str);
      current_str = NULL;
      return NULL;
    }
  }

  free(current_str);
  current_str = NULL;

  return result;
}

char *str_pad(
  const char *str,
  unsigned int length,
  const char *pad_str,
  int side
) {
  if (!*pad_str) {
    return str_copy(str);
  }

  unsigned int string_length = str_length(str);

  if (string_length >= length) {
    return str_copy(str);
  }

  unsigned int length_diff = length - string_length;

  char *result = malloc((length + 1) * sizeof *result);

  if (result == NULL) {
    return NULL;
  }

  unsigned int j = 0;
  unsigned int k = 0;

  if (side == PAD_LEFT) {
    bool original = false;

    for (unsigned int i = 0; i < length; ++i, ++j) {
      if (!original) {
        if (i >= length_diff) {
          original = true;
        } else {
          if (!*(pad_str + k)) {
            k = 0;
          }

          *(result + j) = *(pad_str + k);
          ++k;
          continue;
        }
      }

      *(result + j) = *(str + i - length_diff);
    }
  } else if (side == PAD_BOTH) {
    unsigned int left_pad = length_diff / 2;

    bool left = true;
    bool right = false;

    for (unsigned int i = 0; i < length; ++i, ++j) {
      if (left) {
        if (i >= left_pad) {
          left = false;
          k = 0;
        } else {
          if (!*(pad_str + k)) {
            k = 0;
          }

          *(result + j) = *(pad_str + k);
          ++k;
          continue;
        }
      }

      if (!right) {
        if (!*(str + i - left_pad)) {
          right = true;
        } else {
          *(result + j) = *(str + i - left_pad);
          continue;
        }
      }

        
      if (!*(pad_str + k)) {
        k = 0;
      }

      *(result + j) = *(pad_str + k);
      ++k;
    }
  } else {
    bool original = true;

    for (unsigned int i = 0; i < length; ++i, ++j) {
      if (original) {
        if (!*(str + i)) {
          original = false;
        } else {
          *(result + j) = *(str + i);
          continue;
        }
      }

      if (!*(pad_str + k)) {
        k = 0;
      }

      *(result + j) = *(pad_str + k);
      ++k;
    }
  }

  *(result + j) = '\0';

  return result;
}

char *str_replace(
  const char *str,
  const char *search,
  const char *replace,
  unsigned int count
) {
  if (!*search) {
    return str_copy(str);
  }

  char *result = NULL;
  unsigned int replaces = 0;
  unsigned int j = 0;

  for (unsigned int i = 0; *(str + i); ++i) {
    if (((count == 0) || (replaces < count)) && (*(str + i) == *search)) {
      bool found = true;
      unsigned int k = 1;

      for (; *(search + k); ++k) {
        if (*(str + i + k) != *(search + k)) {
          found = false;
          break;
        }
      }

      if (found) {
        i += k - 1;
        ++replaces;
        k = 0;

        for (; *(replace + k); ++k) {
          if (result == NULL) {
            result = malloc(sizeof *result);
          } else {
            result = realloc(result, (j + 1) * sizeof *result);
          }

          if (result == NULL) {
            return NULL;
          }

          *(result + j++) = *(replace + k);
        }

        continue;
      }
    }

    if (result == NULL) {
      result = malloc(sizeof *result);
    } else {
      result = realloc(result, (j + 1) * sizeof *result);
    }

    if (result == NULL) {
      return NULL;
    }

    *(result + j++) = *(str + i);
  }

  result = realloc(result, (j + 1) * sizeof *result);
  *(result + j) = '\0';

  return result;
}

char **str_split(const char *str, const char *separator) {
  char **result = malloc(sizeof *result);

  if (result == NULL) {
    return NULL;
  }

  *result = malloc(sizeof **result);

  if (*result == NULL) {
    return NULL;
  }

  **result = '\0';

  unsigned int count = 0;

  for (unsigned int i = 0, char_count = 0; *(str + i); ++i) {
    if (*(str + i) == *separator) {
      if (char_count > 0) {
        *(result + count) = realloc(*(result + count), (char_count + 1) * sizeof **result);

        if (*(result + count) == NULL) {
          return NULL;
        }

        *(*(result + count) + char_count) = '\0';

        char_count = 0;
      }

      result = realloc(result, (++count + 1) * sizeof *result);

      if (result == NULL) {
        return NULL;
      }

      *(result + count) = malloc(sizeof **result);

      if (*(result + count) == NULL) {
        return NULL;
      }

      **(result + count) = '\0';
    } else {
      if (char_count > 0) {
        *(result + count) = realloc(*(result + count), (char_count + 1) * sizeof **result);

        if (*(result + count) == NULL) {
          return NULL;
        }
      }

      *(*(result + count) + char_count++) = *(str + i);
    }
  }

  result = realloc(result, (++count + 1) * sizeof *result);

  if (result == NULL) {
    return NULL;
  }

  *(result + count) = NULL;

  return result;
}

char **str_split_n(
  const char *str,
  const char *separator,
  unsigned int n
) {
  char **result = malloc(sizeof *result);

  if (result == NULL) {
    return NULL;
  }

  *result = malloc(sizeof **result);

  if (*result == NULL) {
    return NULL;
  }

  **result = '\0';

  unsigned int count = 0;
  unsigned int char_count = 0;

  for (unsigned int i = 0; *(str + i); ++i) {
    if (((n == 0) || (count + 1 < n)) && (*(str + i) == *separator)) {
      if (char_count > 0) {
        *(result + count) = realloc(*(result + count), (char_count + 1) * sizeof **result);

        if (*(result + count) == NULL) {
          return NULL;
        }

        *(*(result + count) + char_count) = '\0';

        char_count = 0;
      }

      result = realloc(result, (++count + 1) * sizeof *result);

      if (result == NULL) {
        return NULL;
      }

      *(result + count) = malloc(sizeof **result);

      if (*(result + count) == NULL) {
        return NULL;
      }

      **(result + count) = '\0';
    } else {
      if (char_count > 0) {
        *(result + count) = realloc(*(result + count), (char_count + 1) * sizeof **result);

        if (*(result + count) == NULL) {
          return NULL;
        }
      }

      *(*(result + count) + char_count++) = *(str + i);
    }
  }

  if ((n != 0) && (count + 1 == n)) {
    *(result + count) = realloc(*(result + count), (char_count + 1) * sizeof **result);

    if (*(result + count) == NULL) {
      return NULL;
    }

    *(*(result + count) + char_count) = '\0';
  }

  result = realloc(result, (++count + 1) * sizeof *result);

  if (result == NULL) {
    return NULL;
  }

  *(result + count) = NULL;

  return result;
}

char *str_join(char **array, const char *separator) {
  char *result = malloc(sizeof *result);

  if (result == NULL) {
    return NULL;
  }

  unsigned int chars = 0;

  for (unsigned int i = 0; *(array + i) != NULL; ++i) {
    if (i > 0) {
      for (unsigned int j = 0; *(separator + j); ++j, ++chars) {
        if (chars > 0) {
          result = realloc(result, (chars + 1) * sizeof *result);

          if (result == NULL) {
            return NULL;
          }
        }

        *(result + chars) = *(separator + j);
      }
    }

    for (unsigned int j = 0; *(*(array + i) + j); ++j, ++chars) {
      if (chars > 0) {
        result = realloc(result, (chars + 1) * sizeof *result);

        if (result == NULL) {
          return NULL;
        }
      }

      *(result + chars) = *(*(array + i) + j);
    }
  }

  result = realloc(result, (chars + 1) * sizeof *result);

  if (result == NULL) {
    return NULL;
  }

  *(result + chars) = '\0';

  return result;
}

int str_to_int(const char *str) {
  bool negative = false;

  if (*str == '-') {
    negative = true;
    str++;
  } else if (*str == '+') {
    str++;
  }

  int result = 0;

  while (*str) {
    if (*str >= 48 && *str <= 57) {
      result = (result * 10) + (*str - 48);
    } else {
      break;
    }

    str++;
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
    str++;
  } else if (*str == '+') {
    str++;
  }

  unsigned int whole_part = 0;
  float decimal_part = 0;
  bool decimal_point = false;
  unsigned int decimal_count = 0;

  while (*str) {
    if (*str == '.') {
      decimal_point = true;
    } else if (*str >= 48 && *str <= 57) {
      if (decimal_point) {
        decimal_part = (decimal_part * 10) + (*str - 48);
        ++decimal_count;
      } else {
        whole_part = (whole_part * 10) + (*str - 48);
      }
    } else {
      break;
    }

    str++;
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
