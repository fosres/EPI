#include <stdio.h>
#include <stdlib.h>

typedef struct tree
{
	struct tree * left;

	struct tree * right;

	int val;

} tree;

void reverse_order(tree * root)
{
	if ( root == 0x0 ) { return; }	
	
	reverse_order(root->right);	

	printf("%d\n",root->val);

	reverse_order(root->left);
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

int main(void)
{
	tree * root = (tree *)calloc(1,sizeof(tree));

	root->val = 2;

	insert(root,1);

	insert(root,3);

	insert(root,0);

	insert(root,4);

	insert(root,5);

	reverse_order(root);	
}

