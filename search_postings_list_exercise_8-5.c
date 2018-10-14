#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	
	struct Node * link;

	struct Node * jmp;

	int value;

} Node;

static Node * stack[1000];

static Node ** stack_p = &stack[0]-1;

void push(Node * r);

Node * pop( );

int in_stack(Node * r);

void jmp_first(Node * r)
{
	while (!in_stack(r))
	{
		printf("%p ",r);

		push(r);

		r = r->jmp;

	}


	while (r != NULL)
	{
		printf("%p ",r);

		r = r->link;

	}

}

void push(Node * r)
{

	*++stack_p = r;

}

Node * pop()
{
	
	return *stack_p--;

}

int in_stack(Node * r)
{

	Node ** current_p = stack_p;

	while (stack_p > (&stack[0]-1) && pop() != r)
		;

	stack_p = current_p;

	return (stack_p == (&stack[0]-1)) ? 0 : 1;

}

int main()
{


}
