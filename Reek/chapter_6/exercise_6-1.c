#include <stdio.h>

const char * find_char(char const * source, char const * chars)
{
  char key; 

  while ((key = *chars) != '\0')
  {
    const char * source_p = source;

    while (*source_p != '\0' )
    {
      if (*source_p == key )
      {return source_p;}
      source_p++;
    }
    chars++;
  }
  return NULL;
}

int main() 
{
  static char a[1000] = "ABCDEF";
  static char keys[1000] = "EF";
  printf("%s\n",find_char(a,keys));
}

