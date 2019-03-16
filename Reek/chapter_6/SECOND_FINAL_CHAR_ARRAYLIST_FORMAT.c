#include <iostream>

int main() {
  static char * nil = NULL;

  char ** str = &nil;

  char ** str_zero = str;

  *str++ = "I";
  *str++ = "Know";
  *str++ = "This";
  *str++ = "Will";
  *str++ = "Work";
  *str = NULL;

  while (*str_zero != NULL )
  {
    printf("%s\n",*str_zero++);
  }
}
