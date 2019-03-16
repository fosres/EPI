#include <stdio.h>

int main(void) {
  
  static char * nil = NULL;

  char ** str = &nil;

  char ** str_zero = str;

  *str++ = "I";
  *str++ = "Know";
  *str++ = "What";
  *str++ = "I";
  *str++ = "Am";
  *str++ = "Doing!";
  *str = NULL;

  while (*str_zero != NULL )
  {
    printf("%s\n",*str_zero++);
  }
}
