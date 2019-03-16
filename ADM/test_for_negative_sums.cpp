#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using std::cout;
using std::endl;

int main() {

  for ( int i = 0 ; i < 10000; i++)
  {
    int a = (int)(random()/(double)RAND_MAX*100+0.5);
    int b = (int)(random()/(double)RAND_MAX*100+0.5);
    int sign_a = -1+(int)(random()/(double)RAND_MAX*(2)+0.5);
    int sign_b = -1+(int)(random()/(double)RAND_MAX*(2)+0.5);

  cout << "printf(\"%d\\n\",bit_multiply(" << sign_a*a << "," << sign_b*b << "));" << endl;
  
  
  }
}

