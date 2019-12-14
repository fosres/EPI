#include <stdio.h>
#include <stdlib.h>

typedef struct tree
{
	struct tree * left;

	struct tree * right;

	int val;

} tree;


unsigned k = 0;


void k_largest(tree * root)
{
	if ( ( root == 0x0 ) || ( k <= 0 ) ) { return; }

	if ( ( k > 0 ) && ( root->right != 0x0 ) )
	{
		k_largest(root->right);
	}

	if ( ( k > 0 ) )
	{
		printf("%d\n",root->val); k--;
	}

	if ( ( k > 0 ) && ( root->left != 0x0 ) )
	{
		k_largest(root->left);
	}
}

void insert(tree * root, const int val)
{
	if ( (root->left == 0x0) && (val < root->val) )
	{
		root->left = (tree *)calloc(1,sizeof(tree));

		root->left->val = val;
	}

	else if ( (root->right == 0x0) && (val >= root->val) )
	{
		root->right = (tree *)calloc(1,sizeof(tree));

		root->right->val = val;
	}
	
	else if ( val < root->val )
	{
		insert(root->left,val);	
	}

	else if ( val >= root->val )
	{
		insert(root->right,val);	
	}
}

int main(int argc, char ** argv)
{
	k = strtol(argv[1],NULL,10);		

	tree * root = (tree *)calloc(1,sizeof(tree));

	root->val = strtol(argv[2],NULL,10);

	argv = &argv[2];

	while ( *++argv != NULL )
	{
		insert(root,strtol(*argv,NULL,10));
	}
	
	k_largest(root);
}

