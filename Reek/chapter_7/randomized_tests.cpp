
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <float.h>
#include <iostream>
using std::cout;
using std::endl;
#include "printf.h"

void random_lld_tests()
{

  srand(time(NULL));

  long long int random_lld; 
   
   /* random number range: [LLONG_MIN,LLONG_MAX] */

  static int i = 0;

  static long long int ll_to_a;

  while (i < 10000 )
  {
   static const int signs[2] = {1,-1};

   int sign_index = (0+rand()/(double)RAND_MAX*(1-0)+0.5);

  random_lld = signs[sign_index]*(0+rand()/(double)RAND_MAX*(LLONG_MAX)+0.5);
 
  cout << "printf(\"%lld\\n\",lltoa(" << random_lld << "));" << endl;
  
  i++;
  }

}

int main(void) 
{

random_lld_tests();

}

