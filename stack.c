#include <stdio.h>
#include "stack.h"

#define SIZE 1000

static STACK_TYPE arr[SIZE];

static STACK_TYPE * arr_p = &arr[0];

void push(STACK_TYPE in)
{
	if (arr_p < (arr+SIZE))
	{*arr_p++ = in;}
}

void pop()
{
	if (arr_p > (arr+0))
	{ arr_p--;}
}

STACK_TYPE top()
{return  *(arr_p-1);}



STACK_TYPE main()
{
	push(6);
	push(5);
	pop();
	printf("%d\n",top());
}
