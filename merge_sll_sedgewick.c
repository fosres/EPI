#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	struct Node * link;

	int value;
} Node;

Node * merge(Node * l, Node * r)
{
	Node * c = (Node *)malloc(sizeof(Node));

	c->link = NULL; c->value = 0;

	Node * c_zero = c;

	while (l != NULL && r != NULL)
	{
		if (l->value < r->value)
		{
			c->link = l;

			c = c->link;

			l = l->link;

			c->link = NULL;

		}

		else
		{
			c->link = r; c = c->link; r = r->link;

			c->link = NULL;

		}

	}

		c->link = (l == NULL) ? r : l;

		Node * second = c_zero->link;

		free(c_zero);

		return second;

}

	Node * insert_value(Node * root, int in)
	{
		if ( root == NULL)
		{
			return NULL;
		}

		root->link = (Node *)malloc(sizeof(Node));

		root = root->link;

		root->value = in;

		root->link = NULL;

		return root;

	}

	void free_list(Node * root)
	{
		while ( root != NULL)
		{
			Node * q = root->link;

			free(root);

			root = q;			

		}

	}

	void print_list(Node * root)
{

	while (root != NULL)
	{
		printf("%d ",root->value);

		root = root->link;
	}

	printf("\n");


}

int main()
{

	Node * first = (Node *)malloc(sizeof(Node));

	Node * first_z = first;

	first->value = 4; first->link = NULL;

	first = insert_value(first,5);	

	first = insert_value(first,6);

	first = insert_value(first,7);

	first = insert_value(first,8);

	print_list(first_z);

	Node * second = (Node *)malloc(sizeof(Node));

	Node * second_z = second;

	second->value = 2;

	second = insert_value(second,3);

	second = insert_value(second,4);

	second = insert_value(second,5);

	second = insert_value(second,6);

	second = insert_value(second,7);

	print_list(second_z);

	Node * ans = merge(first_z,second_z);

	print_list(ans);
	
	free_list(ans);
	
	free_list(first);	

}
