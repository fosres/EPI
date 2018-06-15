#include <iostream>
#include <stdlib.h>
using std::cout;
using std::endl;

unsigned bit_sum(unsigned a, unsigned b)
{
  unsigned c;

  while (a!=0)
  {
    c = b&a;
    b= b^a;
    c <<= 1;
    a = c;
  }
  return b;
}

unsigned bit_multiply(unsigned a, unsigned b)
{
  unsigned sum = 0;

  while (b != 0)
  {
    if ( b&1 == 1)
      sum = bit_sum(sum,a);
    a <<= 1;
    b >>= 1;
  }

  return sum;
}

int main() {

  cout << bit_multiply(5,6) << endl;
  
}


