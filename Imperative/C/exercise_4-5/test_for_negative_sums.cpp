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
    int sign_a = (int)(random()/(double)RAND_MAX*-1-0.5);
    int sign_b = -(int)(random()/(double)RAND_MAX*-1-0.5);

  cout << "printf(\"%d\\n\",bit_sum(" << sign_a*a << "," << sign_b*b << "));" << endl;
  
  
  }
}
