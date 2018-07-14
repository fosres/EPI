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

int sll_remove(Node ** rootp, Node *node)
{
	int len = 0;

	Node * s = *rootp;

	while ( s != NULL) {len++;s = s->link;}

	int i = 0;

	while ( i < len )
	{
		if ( *rootp+i == node )
		{
			if ( len == 1)
			{*rootp = NULL; return 1;}

			else if ( i == len -1)
			{ (*rootp+i-1)->link = NULL; return 1;}

			else if ( i == 0 )
			{
				*rootp = NULL; return 1; 
			}
			else
			{
				(*rootp+i-1)->link  = (*rootp+i+1);

				return 1;

			}
		}

		i++;

	}

	return 0;

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

	Node * sixth = calloc(1,sizeof(Node));

	sixth->value = 6;

	sixth->link = NULL;
	
	Node ** rootp = &first;

	printf("%p\n",*rootp+4);

	printf("%p\n",fifth);

	printf("%d\n",sll_remove(&second,fourth));

	print_values(second);
}

