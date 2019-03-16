// exercise_4-8-2.cpp

#include <stdio.h>

long int reverseDigits(long int x)
{

	long int num = x;

	long int ans = 0;

	if ( x < 0)
		num *= -1;

	while ( num > 0)
	{

		ans = ans*10 + num%10;

		num /= 10;

	}

	if ( x < 0)
		ans *= -1;

	return ans;

}

int main()
{



}



