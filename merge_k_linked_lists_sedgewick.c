#include <stdio.h>
#include <stdlib.h>

#if 0

Uses mergesort and NOT binary trees

#endif

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

Node * merge_sort(Node *c)
{

	if ( c == NULL || c->link == NULL)
	{
		return c;

	}

	Node * a = c; Node * b = c->link;

	while ( b != NULL && b->link != NULL)
	{
		c = c->link; b = b->link->link;
	}

	b = c->link; c->link = NULL;

	return merge(merge_sort(a),merge_sort(b));

}

Node * mergesort_k_lists(Node ** nap, Node ** nap_stop)
{


	if ( *nap == NULL || *(nap+1) == NULL)
	{
		return *nap;
	}
	
	Node * ans = NULL;

	while ( (nap < nap_stop) )
	{
		ans = merge(ans,merge_sort(*nap));

		nap++;

	}

	return ans;

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

	first->value = 3; first->link = NULL;

	first = insert_value(first,9);	

	first = insert_value(first,6);

	first = insert_value(first,5);

	first = insert_value(first,7);

	print_list(first_z);

	Node * second = (Node *)malloc(sizeof(Node));

	Node * second_z = second;

	second->value = 7;

	second = insert_value(second,9);

	second = insert_value(second,4);

	second = insert_value(second,2);

	second = insert_value(second,10);

	second = insert_value(second,5);

	print_list(second_z);

	Node * na[2];

	na[0] = first_z;

	na[1] = second_z;

	Node * ans = mergesort_k_lists(na,na+2);

	Node * q = merge_sort(ans);	

	print_list(ans);

	print_list(q);
	
	free_list(ans);


}
