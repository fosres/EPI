#include <stdio.h>

void reverse(int a[], const int len)
{
	for (int i = 0, j = len-1; i < j; i++, j--)
	{
		int temp = a[i];

		a[i] = a[j];

		a[j] = temp;
	}
}

void inc_arr(int a[], int len)
{
	int IS_NEG = 0;	
	if ( a[0] < 0)
	{ IS_NEG = 1; a[0] = -a[0];}

	int temp = 0;
	
	int i = 0;
	while (i < len)
	{
		temp = temp * 10 + a[i];

		i++;
	}

	if (!IS_NEG)
	{temp++;}
	else
	{temp--;}

	i = 0;
	
	len = 0;

	do
	{
		a[i] = temp%10;
	
		i++; len++;

		temp /= 10;
	}while (temp > 0);

	reverse(a,len);

	if (IS_NEG)
	{
		a[0] = -a[0];
	}
}

int main()
{
	int a[5] = {-4,5,6,7};

	inc_arr(a,4); // input for len must be actual # of digits initialized in array, NOT sizeof(a)/sizeof(int)

	for ( int i = 0; i < 4 ; i++)
	{
		printf("%d\n",a[i]);
	}
}
