#include <stdio.h>
#include <stdlib.h>
#include "Node.h"

void reverse (int * a, int len)
{
	for ( int i = 0, j = len - 1; i < j; i++, j--)
	{
		int temp = a[i];

		a[i] = a[j];

		a[j] = temp;

	}

}

int * inc_arr(int *a, int len)
{
	
	int result_len = 0;

	reverse(a,len); int * a_end = (a + len - 1);

	*a = *a + 1; int carry = *a/10; *a = *a%10; 

	Node * result = (Node *)calloc(1,sizeof(Node));
	
	Node * result_zero = result;

	Node * next = (Node *)calloc(1,sizeof(Node));
	
	result->link = next;
	
	result->value = *a; result = result->link; result_len++;

	while (a <= a_end)
	{
		if ( carry != 0)
		{
			result->value = (carry + *a)%10; 

			carry = (carry + *a)/10;
		}

		else
		{ result->value = *a; carry = 0;}

		Node * next = (Node *)calloc(1,sizeof(Node));

		result->link = next;
		
		result = result->link; result_len++;

		a++;
	}

	if ( carry != 0)
	{ 
		result->value = carry; result_len++;

		result->link = NULL;
	}

	else
	{ result = NULL; }

	int a_final[result_len]; int *a_f = a_final;

	while (result_zero != NULL)
	{
		*a_f++ = (result_zero->value);
		
		result_zero = result_zero->link;
	}

	reverse(a_final,result_len);

	return a_final;

}


int main()
{
	int a[3] = {1,2,9};

	int * b = inc_arr(a,3);

	printf("%d\n",*b++);
	printf("%d\n",*b++);
	printf("%d\n",*b++);
	printf("%d\n",*b++);
	printf("%d\n",*b++);

}
