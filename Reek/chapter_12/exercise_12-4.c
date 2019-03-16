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

Node * sll_reverse(Node * first)
{
	if ( first == NULL) {return NULL;}	

	Node * reverse = calloc(1,sizeof(Node)); Node *r = reverse; Node * r_zero = reverse;
	
	Node * f = first;

	int len = 0;

	while ( f != NULL ) {f = f->link; len++;}

	Node * tail = (first + len - 1);	
	
	for ( int j = len-1; j >= 1; j--)
	{
		first[j].link = &first[j-1];
	}

	first[0].link = NULL;
	
	return tail;
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
	
	print_values(sll_reverse(first));

	Node ** rootp = &first;

	printf("%d\n",(*rootp+4)->value);

	printf("%p\n",fifth);
}
