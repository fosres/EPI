//exercise_4-2.c

#include <stdio.h>
#include <limits.h>

unsigned long long int reverse(unsigned long long int x)
{

	unsigned long long int rev = 0;

	while (x > 0)
	{

		rev <<= 1;

		rev = rev + (x&1);

		x >>= 1;

	}

	return rev;


}

int main()
{

	for (int i = 0; i < INT_MAX; i++)
		printf("%llu\n",reverse(i));


}
