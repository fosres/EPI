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

void sll_reverse(Node * first)
{
	Node * f = first;	

	while ( f != NULL ) f++;
	
	f--; // now pointing to last element

	Node * reverse = calloc(1,sizeof(Node)); Node * r_zero = reverse;
	
	while (reverse = f, reverse++, f--, f >= first)
		;

	reverse = NULL;

	first = r_zero;	


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
	
	first->link = second;

	second->link = third;

	third->link = fourth;

	fourth->link = fifth;
	
	fifth->link = NULL;
#if 0
	sll_reverse(first);
#endif
	Node * c = calloc(1,sizeof(Node));

	int i = 0;

	while (i++ < 5) {c++->link = calloc(1,sizeof(Node));}
	
	c->link = NULL;

	i = 0;

	while (i++ < 5) {printf("%d\n",c++->value = i);}

}
