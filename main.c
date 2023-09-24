#include <stdio.h>

#include "strings.h"

int main(void) {
  const char *str = "Hello world!";

  printf("%s\n", str);
  printf("Length: %d\n", str_length(str));

  return 0;
}
