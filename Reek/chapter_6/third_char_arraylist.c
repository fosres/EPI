#include <stdio.h>

int main(void) {
  
  static char * a;
  
  char ** str = &a;

  char ** str_zero = str;

  *str++ = "Slap";

  *str = NULL;

  while (*str_zero != NULL )
  {
    printf("%s\n:",*str_zero++);
  }
}
