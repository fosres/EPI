#include <stdio.h>

char * find_char(char const * source, char const * chars)
{
  char key; 

  while ((key = *chars) != '\0')
  {
    char * source_p = (char*)source;

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
  static char keys[1000] = "F";
  printf("%s\n",find_char(a,keys));
}

