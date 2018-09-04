#include <stdio.h>



static char stack[1000];

static char * stack_p = (&stack[0]-1);

void push(char c);

char pop();

char * normpath(char * s)
{
  while ( *s != '\0' )
  {
    if ( *s == '/' )
    {
      if ( *stack_p == '/' )
      { }
      else
      { push(*s); }

    }

    else if ( *s == '.' )
    {
      if ( *(s+1) == '.' )
      {
        pop(); // remove first '/'

        while ( *stack_p != '/' )
        { pop(); }

      }

      else // *stack_p == '/'
      { }
      
    }    
        
  else // regular alphanum
  { push(*s); }

    
  s++;

  }

  return &stack[0];

}

void push( char c )
{ *++stack_p = c; }

char pop()
{ return *stack_p--;}


  



int main(void) {

  
  
  char * str = "///////";

  printf("%s\n",normpath(str));
  

  return 0;
}
