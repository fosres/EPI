#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "mystrstr.h"


#define MAX_LENGTH 1000


char * random_string()
{

  
  srand(time(NULL));
  
  static char r[MAX_LENGTH]; 

  char * r_p = r;

  *(r + MAX_LENGTH ) = '\0';

  int len = rand()/(double)RAND_MAX*MAX_LENGTH + 0.5;

  while (r_p < (r + len) )
  {
    *r_p++ = (char)('a' + rand()/(double)RAND_MAX*('z'-'a') + 0.5);
  }

  return r;
}

void mystrstr_test()
{
  srand(time(NULL));
  
  static char * nil = NULL;

  char ** strings = &nil;

  char **str_zero = strings; char **str_zero_cp = str_zero;

  while (strings < (str_zero + 100) )
  {
    *strings++ = random_string();
  }

  char ** substrings = &nil; 
  
  char ** sub_zero = substrings;

  while (substrings < (sub_zero + 100) )
  {
    int rand_index = (int)(rand()/(double)RAND_MAX*MAX_LENGTH);

    *substrings++ = ((*str_zero) + rand_index);

    str_zero++;
  }

  *substrings = nil;

  while (*str_zero_cp != NULL )
  {
    printf("%s\n%s\n%d\n",*str_zero_cp,*sub_zero,mystrstr(*str_zero_cp,*sub_zero)==strstr(*str_zero_cp,*sub_zero));

    str_zero_cp++; sub_zero++;
  }
}

int main(void) {
	

	static char * nil = NULL;	
	char **str = &nil;
	char **str_zero = str;

	*str++ = "That"; 
	*str = "at";

	char *source = *str_zero;

	char *target = *str;

	del_substr(source,target);	

	return 0;
}
