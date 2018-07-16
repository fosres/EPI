#include <stdio.h>
#include "stack.h"

#define SIZE 1000

static STACK_TYPE arr[SIZE];

static STACK_TYPE * arr_p = (arr-1);

static int max;

void push(STACK_TYPE in)
{
	if (arr_p < (arr+SIZE))
	{*++arr_p = in;}
	if ( in > max)
	{ max = in;}
}

void pop()
{
	if (arr_p >= (arr+0))
	{ --arr_p;}
}

STACK_TYPE print_max()
{ return max;}

STACK_TYPE top()
{	if (arr_p >= arr)
		{return  *(arr_p);}
	else {return printf("No values in stack.Return value of printf:");}
}



STACK_TYPE main()
{
#if 0
	push(6);
	push(5);
	pop();
	printf("%d\n",top());
	push(7);
	printf("%d\n",top());
	pop();
	pop();
	printf("%d\n",top());
	push(13);
	push(81);
	printf("%d\n",top());
	push(31);
	push(32);
	printf("%d\n",print_max());
#endif
	push(1);
	push(2);
	push(31);
	push(14);
	printf("%d\n",top());
	printf("%d\n",print_max());
	push(30);
	push(29);
	push(28);
	printf("%d\n",top());
	printf("%d\n",print_max());
	
	

	
}
