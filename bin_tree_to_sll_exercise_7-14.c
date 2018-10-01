#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  struct Node * link;

  int value;
} Node;

typedef struct tree
{
  struct tree * left;

  struct tree * right;

  int value;

} tree;

void in_order(tree * root)
{
  if ( root != NULL)
  {
    in_order(root->left);

    printf("%d ",root->value);

    in_order(root->right);
  }
}

Node * insert_node(Node * root, int in)
{
  if ( root == NULL) {return NULL;}

  while (root->link != NULL)
  {
    root = root->link;
  }

  root->link = (Node *)malloc(sizeof(Node));

  root = root->link;

  root->value = in;

  root->link = NULL;

  return root;
}

void insert_to_tree(tree ** root, int in)
{
  if ( *root == NULL)
  {
    *root = (tree *)malloc(sizeof(tree));

    (*root)->left = NULL; (*root)->right = NULL;

    (*root)->value = in;

    return;
  }

  else if (in < (*root)->value)
  {
    insert_to_tree(&((*root)->left),in);
  }
  
  else
  {
    insert_to_tree(&((*root)->right),in);
  }

}



void tree_to_sll(tree * root, Node * node)
{
  if ( root != NULL)
  {
    tree_to_sll(root->left,node);

    node = insert_node(node,root->value);

    tree_to_sll(root->right,node);
  }
}

void make_sll(tree * root, Node ** node)
{
  tree_to_sll(root,*node);

  Node * second = (*node)->link;

  Node ** first_del = node;

  free(*node);

  *first_del = second;
}


void print_list(Node * root)
{
  while (root != NULL)
  {
    printf("%d ",root->value);

    root = root->link;
  }

  printf("\n\n");
}

void free_sll(Node * node)
{
  Node * q;

  while (node != NULL)
  {
    q = node->link;

    free(node);

    node = q;
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

  top->value = 3;

  insert_to_tree(&top,16);

  insert_to_tree(&top,4);

  insert_to_tree(&top,6);

  insert_to_tree(&top,7);

  insert_to_tree(&top,8);

  insert_to_tree(&top,9);

  insert_to_tree(&top,10);

  insert_to_tree(&top,11);

  insert_to_tree(&top,112);

  insert_to_tree(&top,13);

  in_order(top);

  printf("\n");


  Node * first = (Node *)malloc(sizeof(Node));

  make_sll(top,&first);

  print_list(first);

  free_sll(first);

  free_tree(top);

  return 0;
}
