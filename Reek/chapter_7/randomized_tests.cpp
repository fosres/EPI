
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <float.h>
#include <iostream>
using std::cout;
using std::endl;
#include "printf.h"

#define NUM_TESTS 10000

void generate_random_lltoa_tests()
{

  srand(time(NULL));

  long long int random_lld; 
   
   /* random number range: [LLONG_MIN,LLONG_MAX] */

  static int i = 0;

  static long long int ll_to_a;

  while (i < NUM_TESTS )
  {
   static const int signs[2] = {1,-1};

   int sign_index = (0+rand()/(double)RAND_MAX*(1-0)+0.5);

  random_lld = signs[sign_index]*(0+rand()/(double)RAND_MAX*(LLONG_MAX)+0.5);
 
  cout << "printf(\"%s\\n\",lltoa(" << random_lld << "));" << endl;
  
  i++;
  }

}

void generate_random_ftoa_tests()
{

  srand(time(NULL));

  static double random_f; 
   
   /* random number range: [LLONG_MIN,LLONG_MAX] */

  static int i = 0;

  static long long int f_to_a;

  while (i < NUM_TESTS )
  {
   static const int signs[2] = {1,-1};

   int sign_index = (0+rand()/(double)RAND_MAX*(1-0)+0.5);

  random_f = signs[sign_index]*(0+rand()/(double)RAND_MAX*(LLONG_MAX)+0.5);

  int rand_power = (int)(0+rand()/(double)RAND_MAX*(15-0)+0.5);
 
  cout << "putchar('\\n');\nftoa(" << random_f << "," << rand_power << ");" << endl;
  
  i++;
  }

}

int main(void) 
{
	
	generate_random_ftoa_tests();

}

