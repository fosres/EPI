#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <float.h>
#include <iostream>
using std::cout;
using std::endl;


long long int random_lld()
{
  

  static const int signs[2] = {1,-1};

  int sign_index = (0+rand()/(double)RAND_MAX*(1-0)+0.5);

  return signs[sign_index]*(0+rand()/(double)RAND_MAX*(LLONG_MAX)+0.5); 
  
  /* random number range: [LLONG_MIN,LLONG_MAX] */

}

int main(void) {
  
  const int NUMBER_OF_TESTS = 10000; 

  static int i;

  while (i < NUMBER_OF_TESTS )
  {
  cout << random_lld() << endl;
  i++;
  }
  
  
}

