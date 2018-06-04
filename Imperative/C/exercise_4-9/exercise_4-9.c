//exercise_4-9.c

#include <stdio.h>
#include <stdbool.h>

bool isPalindrome(int x)
{

	if ( x < 0)
		return 0;
	if ( x == 0)
		return 1;

	int num = x;

	int rev = 0;

	while ( num > 0 )
	{

		rev = rev * 10 + num % 10;

		num /= 10;


	}

	if ( rev == x )
		return 1;
	else // rev != x
		return 0;
}

int main()
{


}
