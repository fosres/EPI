#include <stdio.h>
#include "NODE.h"
#include <stdlib.h>

int num_nodes(Node * in)
{

	Node * c = in;
	
	int i = 0;

	while ( c != NULL )
	{
		i++;

		c = c->link;
	}

	return i;

}

int main()

{

	Node * x = calloc(1,sizeof(Node));

	Node * y = calloc(1,sizeof(Node));

	Node * z = calloc(1,sizeof(Node));

	Node * a = calloc(1,sizeof(Node));

	x->link = y;

	y->link = z;

	z->link = a;

	a->link = NULL;


	printf("%d\n",num_nodes(x));

	return 0;
}
