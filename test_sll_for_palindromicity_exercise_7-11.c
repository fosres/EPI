#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  struct Node * link;

  int value;
} Node;

typedef struct DNode
{
  struct DNode * fwd;

  struct DNode * bwd;

  Node * node;
} DNode;

int test_palindromicity(Node * root)
{
  if (root == NULL) {return 1;}

  DNode * cpy = (DNode *)malloc(sizeof(DNode));

  cpy->bwd = NULL;

  DNode * cpy_i = cpy;

  while (1)
  {
    if (root->link == NULL)
    {
      cpy->node = root;

      cpy->fwd = NULL;

      break;
    }

    cpy->node = root;

    cpy->fwd = (DNode *)malloc(sizeof(DNode));

    cpy->fwd->bwd = cpy;

    cpy = cpy->fwd;

    root = root->link;
  }

  while ((cpy_i != cpy)&&(cpy_i->fwd != cpy))
  //this will not work for slls of size 2 nodes
  {
    if( (cpy_i->node->value) != (cpy->node->value))
    {
      return 0;
    }

    cpy_i = cpy_i->fwd;

    cpy = cpy->bwd;
  }

  if (cpy_i->node->value != cpy->node->value)
  {
    return 0;
  }

  return 1;
}

int main(void) 
{
  Node * first = (Node *)malloc(sizeof(Node));

  first->value = 7;

  Node * second = (Node *)malloc(sizeof(Node));

  second->value = 9;

  Node * third = (Node *)malloc(sizeof(Node));

  third->value = 9;

  Node * fourth = (Node *)malloc(sizeof(Node));

  fourth->value = 6;

  first->link = second;

  second->link = third;

  third->link = fourth;

  fourth->link = NULL;

  printf("%d\n",test_palindromicity(first));
}
