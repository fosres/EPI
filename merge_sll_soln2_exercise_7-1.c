#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	struct Node * link;

	int value;
} Node;

Node * merge(Node * first, Node * second)
{
	Node * root = (Node *)malloc(sizeof(Node));

	Node * root_zero = root;

	root->value = 0; root->link = NULL;

	while (first != NULL || second != NULL)
	{

		if ( first == NULL)
		{
			root->link = (Node *)malloc(sizeof(Node));

			root = root->link; root->value = second->value;

			second = second->link; root->link = NULL;

		}

		else if (second == NULL)
		{

			root->link = (Node *)malloc(sizeof(Node));

			root = root->link; root->value = first->value;

			first = first->link; root->link = NULL;

		}

		else if (first->value < second->value)
		{
			root->link = (Node *)malloc(sizeof(Node));

			root = root->link; root->value = first->value;

			root->link = (Node *)malloc(sizeof(Node));

			root = root->link;

			root->value = second->value;

			root->link = NULL;

			first = first->link;

			second = second->link;

		}

		else
		{

			root->link = (Node *)malloc(sizeof(Node));

			root = root->link; root->value = second->value;

			root->link = (Node *)malloc(sizeof(Node));

			root = root->link;

			root->value = first->value;

			root->link = NULL;

			first = first->link;

			second = second->link;

		}


	}

	Node * second_node = root_zero->link;

	free(root_zero);

	return second_node;


}

Node * insert_value(Node * node, int in)
{
	if (node == NULL) {return NULL;}

	while (node->link != NULL)
	{ node = node->link; }

	node->link = (Node *)malloc(sizeof(Node));

	node = node->link;

	node->value = in;

	node->link = NULL;

	return node;


}

void print_sll(Node * root)
{
	while (root != NULL)
	{
	
		printf("%d ",root->value);

		root = root->link;
	}

}

void free_sll(Node * root)
{
	Node * q;
	while ( root != NULL)
	{
		q = root->link;

		free(root);

		root = q;

	}

}


int main(void)
{
	
	Node * first = (Node *)malloc(sizeof(Node));

	first->link = NULL; first->value = 3;

	Node * first_z = first;

	first = insert_value(first,5);

	first = insert_value(first,8);

	first = insert_value(first,10);

	Node * second = (Node *)malloc(sizeof(Node));

	Node * second_z = second;

	second->link = NULL; second->value = 5;

	second = insert_value(second,7);

	second = insert_value(second,9);

	second = insert_value(second,11);

	second = insert_value(second,13);

	Node * ans = merge(first_z,second_z);

	print_sll(ans);
	
	free_sll(ans);

	free_sll(first_z);

	free_sll(second_z);

return 0;

}
