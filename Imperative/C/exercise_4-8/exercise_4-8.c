// exercise_4-8-2.cpp

#include <stdio.h>

int reverseDigits(int x)
{

	int num = x;

	int ans = 0;

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

	printf("%d\n",reverseDigits(0));
	printf("%d\n",reverseDigits(-312));
	printf("%d\n",reverseDigits(12345));
	

}



