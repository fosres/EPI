#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  struct Node * link;
} Node;

typedef struct tree
{
  struct tree * left;

  struct tree * right; 

  Node * node;

} tree;

int insert(tree ** rootp, Node * in);

int insert_both(tree ** rootp,Node * first, Node * second);

int overlap_test(Node * first, Node * second)
{
  tree * root = (tree *)malloc(sizeof(tree));

  root->left = NULL; root->right = NULL;

  root->node = NULL;

  if ( insert_both(&root,first,second) == 0 )
  {
    free(root); return 0;
  }

  free(root); return 1;
}

int insert_both(tree ** rootp, Node * first, Node * second)
{
  if ( first == NULL && second == NULL )
  { return 0; }

  else if (first == NULL && insert(rootp,second) == 0 )
  {
    return insert_both(rootp,first,second->link);
  }

  else if (second == NULL && insert(rootp,first) == 0)
  {
    return insert_both(rootp,first->link,second);
  }

  else if (insert(rootp,first) == 0 && insert(rootp,second) == 0 )
  {
    return insert_both(rootp,first->link,second->link);
  }

  return 1;
}

int insert(tree ** rootp, Node * in )
{
  if ( in == NULL )
  {
    return 0;
  }

  else if ( (*rootp) == NULL )
  {
    tree * p = (tree *)malloc(sizeof(tree));

    p->left = NULL; p->right = NULL;

    p->node = in;

    (*rootp) = p; 

    return 0;
  }

  else if ( in < (*rootp)->node )
  {
    return insert(  &((*rootp)->left),in);
  }

  else if ( in > (*rootp)->node )
  {
    return insert( &((*rootp)->right), in );
  }

  else // in == (*rootp)->node
  {
    return 1;
  }
}

int main(void) {

  Node * first = (Node *)malloc(sizeof(Node));

  Node * second = (Node *)malloc(sizeof(Node));

  Node * third = (Node *)malloc(sizeof(Node));

  Node * fourth = (Node *)malloc(sizeof(Node));
  
  Node * fifth = (Node *)malloc(sizeof(Node));

  Node * sixth = (Node *)malloc(sizeof(Node));

  Node * seventh = (Node *)malloc(sizeof(Node));

  Node * eighth = (Node *)malloc(sizeof(Node));

  first->link = second;

  second->link = NULL;

  third->link = fourth;

  fourth->link = fifth;

  fifth->link = second;

  sixth->link = seventh;

  seventh->link = eighth;

  eighth->link = NULL;


  printf("%d\n",overlap_test(first,third));

  free(first);

  free(second);

  free(third);

  free(fourth);

  free(fifth);

  free(sixth);

  free(seventh);

  free(eighth);

  return 0;
}
