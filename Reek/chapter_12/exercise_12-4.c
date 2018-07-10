#include <stdio.h>
#include <stdlib.h>
#include "singly-linked-list.h"

int sll_length(Node * first)
{
	
	int i = 0;

	Node * c = first;

	while ( c != NULL )
	{
		c = c->link;

		i++;

	}

	return i;

}

Node * sll_reverse( Node * first)
{
	if (first == NULL)
	{ return NULL; }

	Node * previous = calloc(1,sizeof( Node));

	previous = first;

	Node * c = calloc(1,sizeof(Node));

	c = first->link;

	previous->link = NULL;

	Node * next = calloc(1,sizeof(Node));

	next = c;

	while (next != NULL)
	{
		
		if (previous==first) // second
		{next = c->link; c->link = previous; previous = next;}
		else
		{
			previous = next;
			
			c = previous->link;

			next = c->link;

			c->link = previous;

		}

	}

	return c;

}

void print_values( Node * head)
{
	
	Node * c = head;

	while ( c != NULL )
	{
		printf("%d\n",c->value);

		c = c->link;
	}

}


int main()
{
	Node * first = calloc(1,sizeof(Node));
	
	first->value = 1;


	Node * second = calloc(1,sizeof(Node));
	
	second->value = 2;


	Node * third = calloc(1,sizeof(Node));

	third->value = 3;


	Node * fourth = calloc(1,sizeof(Node));

	fourth->value = 4;


	Node * fifth = calloc(1,sizeof(Node));

	fifth->value = 5;

	fifth->link = NULL;
	
	first->link = second;

	second->link = third;

	third->link = fourth;

	fourth->link = fifth;

	Node * rev = sll_reverse(first);
	
	printf("%d\n",rev->value);
//	print_values(rev);
}
