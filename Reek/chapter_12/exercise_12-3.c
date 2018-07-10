#include <stdio.h>
#include <stdlib.h>
#include "dll.h"

// return -1 if NOT in memory, return 0 if value alreayd in list, return 1 if
// value was added.

int dll_insert(Node * head, Node * tail, const int insert_value)
{

	if ( head == NULL ) { return -1; }

	Node * c = head;

	Node * to_insert = calloc(1,sizeof(Node)); to_insert->value = insert_value;

	while (c->value < insert_value && c != NULL)
	{c = c->fwd;}

	if (c == NULL) //node must be added after tail
	{
		int temp = tail->value;

		tail->value = to_insert->value;

		tail->fwd = NULL;

		dll_insert(head,tail,temp);
	}

	if ( c->value == insert_value)
	{ return 0;}
	
	if ( c == head )
	{
		int temp = head->value;

		head->value = to_insert->value;

		dll_insert(head,tail,temp);
	}

	else
	{
		
		Node * previous = c->bwd; //this is why program fails when c==head

		c->bwd = to_insert;

		to_insert->fwd = c;

		to_insert->bwd = previous;

		previous->fwd = to_insert;


	}
	return 1;
}

void print_values(Node * head)
{
	
	Node * c = head;

	while ( c != NULL )
	{
		printf("%d\n",c->value);

		c = c->fwd;
	}

}



int main()
{

	Node * head = calloc(1,sizeof(Node));

	head->value = 1;

	head->bwd = NULL;

	Node * tail = calloc(1,sizeof(Node));

	head->fwd = tail;

	tail->value = 100;

	tail->fwd = NULL;

	tail->bwd = head;

	dll_insert(head,tail,23);

	print_values(head);

	dll_insert(head,tail,57);
	
	print_values(head);

	dll_insert(head,tail,99);

	print_values(head);

	dll_insert(head,tail,-1);

	print_values(head);

	dll_insert(head,tail,-10);

	print_values(head);

	dll_insert(head,tail,58);

	print_values(head);

	dll_insert(head,tail,98);

	print_values(head);

	dll_insert(head,tail,-100);

	print_values(head);

	dll_insert(head,tail,102);

	print_values(head);

	return 0;
}
