#include <stdio.h>
#include <stdlib.h>

typedef struct tree
{
  struct tree * left;

  struct tree * right;

  int value;

} tree;

void insert_root(tree ** root, int in)
{
  if (*root == NULL)
  {
    *root = (tree *)malloc(sizeof(tree));

    (*root)->left = NULL;

    (*root)->right = NULL;

    (*root)->value = in;

    return;
  }

  else if (in < (*root)->value)
  {
    insert_root(&((*root)->left),in);
  }

  else
  {
    insert_root(&((*root)->right),in);
  }
}

void reverse_order(tree * root)
{
  if ( root != NULL)
  {
    reverse_order(root->right);

    printf("%d ",root->value);

    reverse_order(root->left);
  }
}

void free_tree(tree * root)
{
  if ( root != NULL)
  {
    free_tree(root->left);

    free_tree(root->right);

    free(root);
  }
}

int main(void) {

  tree * top = (tree *)malloc(sizeof(tree));

  top->value = 16;

  top->left = NULL;

  top->right = NULL;

  insert_root(&top,3);

  insert_root(&top,6);

  insert_root(&top,7);

  insert_root(&top,0);

  reverse_order(top);

  free_tree(top);
  

  return 0;
}
