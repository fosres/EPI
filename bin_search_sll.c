#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	struct Node * link;
	
	int value;
} Node;

Node * bin_search(Node * c, int key)
{


	if (c == NULL) {return c;}

	Node * a = c;

	Node * b = c->link;

	while ( b != NULL && b->link != NULL)
	{ c = c->link; b = b->link->link; }

	b = c->link; c->link = NULL;

	if ( a->value == key)
	{ return a;}
	
	if (b != NULL && b->value == key)
	{ return b; }

	if ( key < a->value)
	{ return NULL; }

	if ( b != NULL && key > b->value )
	{ return bin_search(b,key); }

	if ( b == NULL && key > c->value)
	{ return NULL; }

	if (key > a->value)
	{ return bin_search(a,key); }

	return NULL;

}

void free_list(Node * r)
{

	while ( r != NULL)
	{
		Node * q = r->link;
		
		free(r);

		r = q;
	}

}


int main()
{

	Node * first = (Node *)malloc(sizeof(Node));

	first->value = 3;

	Node * second = (Node *)malloc(sizeof(Node));
	
	second->value = 6;

	Node * third = (Node *)malloc(sizeof(Node));

	third->value = 7;

	first->link = second;

	second->link = third;

	third->link = NULL;

	Node * ans = bin_search(first,2);

	if ( ans != NULL)
	{

	printf("%p %d\n",ans,ans->value);

	}

	else // (ans == NULL)
	{
	
	printf("%p\n", ans);

	}


	free_list(first);	
	

}
