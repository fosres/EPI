#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	
	struct Node * link;

	int value;

} Node;

Node * insert_node(Node * root, Node * in)
{

	if ( root == NULL)
	{ return NULL; }

	while ( root->link != NULL )
	{ root = root->link; }

	if ( in == NULL )
	{ return root; }

	root->link = in;

	root = root->link;

	return root;

}

void print_list(Node * root)
{

	while ( root != NULL)
	{ printf("%d ",root->value); root = root->link; }

	printf("\n");

}

void free_list(Node * root)
{
	while (root != NULL)
	{
		Node * q = root->link;

		free(root);

		root = q;

	}
}

int main()
{

	Node * a = (malloc(sizeof(Node)));

	Node * a_zero = a;

	Node * b = (malloc(sizeof(Node)));

	b->value = 5; b->link = NULL;	

	a->value = 3; a->link = NULL;

	a = insert_node(a,b);

	print_list(a_zero);
	
	free_list(a_zero);
}


