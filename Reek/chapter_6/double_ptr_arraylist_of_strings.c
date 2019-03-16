#include <stdio.h>
#include <string.h>




int main()
{
  
  
  char ** str;

  char ** str_zero = str;
  
  *str++ = "Pigs";
  *str++ = "Sloth";
  *str++ = "Terror";
  *str++ = "Mr. Nightmare";
  *str++ = "Guon";
  *str = NULL;


  while (*str_zero != NULL )
  {
    printf("%s\n",*str_zero++);
  }
 
   
  return 0;
}
