#include <iostream>
#include <stdlib.h>
using std::cout;
using std::endl;

int bit_sum(int a, int b)
{
  int c;

  while (a!=0)
  {
    c = b&a;
    b= b^a;
    c <<= 1;
    a = c;
  }
  return b;
}

int bit_multiply(int a, int b)
{
  int sum = 0;
  int sign;
  if ((a<0)^(b<0))
  {
    sign = -1;
  }
  else //either both a and b pos or neg
  {
    sign = 1;
  }
  
  a = abs(a);
  b = abs(b);

  while (b != 0)
  {
    if ( b&1 == 1)
      sum = bit_sum(sum,a);
    a <<= 1;
    b >>= 1;
  }
  if (sign == -1)
  {
    return -sum;
  }

  return sum;
}

int main() {
  cout << bit_multiply(5,6) << endl;
  
}



