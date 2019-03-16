#include <stdio.h>
#include <stdlib.h>
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


int main(int argc, char ** argv)
{
  int exit_status = EXIT_SUCCESS; 
   
   static char buf[1024];

   int linenum = 0;

   char ** argv_end = &argv[0] + argc;

   char * search_str = *++argv;
   
   FILE * in = NULL;

while ( *++argv != NULL  )
{

  in = fopen(*argv,"r+"); 
   
   if ( in == NULL )
   {
        perror(*argv);
        
        exit_status = EXIT_FAILURE;
   }

   linenum = 0;
    
    while (fgets(buf,1024,in) != NULL)
    {
      
        linenum++; 
       
        if ( mystrstr(buf,search_str) != NULL ) //argv[1] is the search string
        { 
            printf("%s: Line %d: %s\n",*argv,linenum,buf);
        
        }
        
    }

    if (fclose(in) != 0)
    {
        perror("fclose");

        exit(EXIT_FAILURE);
    }

}


return exit_status;
}
