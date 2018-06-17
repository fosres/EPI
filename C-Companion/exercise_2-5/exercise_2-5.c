#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int statements(int a, int b)
{
  a ^= b ^= a ^= b;
  return a;

}

int method(int a, int b)
{
  a = a ^ b;

  b = b ^ a;

  a = a ^ b; 

  return a;
}

int randomized_values()
{

	int x = (int)((random()/(double)RAND_MAX)*INT_MAX + 0.5);

	return x;

}

int main()
{
 
	for ( int i = 0; i < 10000; i++)
		printf("%d\n",statements(randomized_values(),randomized_values()));

}
