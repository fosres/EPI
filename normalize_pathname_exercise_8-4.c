#include <stdio.h>



char stack[1000];

char * stack_p = (&stack[0]-1);

void push(char c);

void pop();

char * normpath(char * s)
{
  while ( *s != '\0' )
  {
    if ( *s == '/' )
    {
      
      if ( *stack_p == '/' && stack_p >= &stack[0] )
      { }
      
      else
      { push(*s); }

    }

    else if ( *s == '.' )
    {
      if ( *stack_p == '/' && *(s+1) == '.' )
      {
        if ( stack_p <= &stack[0] ) 
        { return "Error: moving above root directory!"; }
        
        pop(); // remove first '/'

        while ( *stack_p != '/' )
        { pop(); }

        s =  (s + 2);

        continue;

      

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

void pop()
{ *stack_p-- = '\0';}


  



int main(void) {

  
  
  char * str = "/usr/./////./////.//////././//////.//////lib/slib/////../../../..";

  printf("%s\n",normpath(str));
  

  return 0;
}
