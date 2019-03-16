#include <stdio.h>
#include <string.h>

char * mystrstr(char * s, char *t)
{
  if ( *s == '\0' && *s == *t )
  { return s; }

  if (*t == '\0')
  { return &s[strlen(s)];}

  char * s_start; char * t_zero = t;

  while (*s != '\0')
  {
    if (*s != *t)
    {
      s++;

      continue;
    }

    s_start = s;

    while (*t != '\0' && *s == *t)
    {
      s++; t++;
    }

    if ( (*t != '\0') && (*(s-1) != t[strlen(t_zero)-1]) )
    {
      s = s_start; s++; t = t_zero;
    }

    else
    {
      return s_start;
    }
  }

  return NULL;

}

int main(void) 
{
  char * t = "Hello world!\0";

  char * s = "world\0";

  printf("%p\n",s+6);

  printf("%p\n",mystrstr(s,t));
}
