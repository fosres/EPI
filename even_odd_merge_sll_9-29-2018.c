#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  struct Node * link;
} Node;

typedef struct DNode
{
  struct DNode * fwd;

  struct DNode * bwd;

  Node * node;
} DNode;

void even_odd_merge(Node * root)
{
  if (root == NULL) {return;}

  Node * root_cp = root;

  DNode * dnode = (DNode *)malloc(sizeof(DNode));

  dnode->bwd = NULL;

  int len = 0;

  while(1)
  {
    if (root_cp->link == NULL)
    {
      dnode->node = root_cp; len++;

      dnode->fwd = NULL;

      break;
    }

    dnode->node = root_cp; len++;

    dnode->fwd = (DNode *)malloc(sizeof(DNode));

    dnode->fwd->bwd = dnode;

    dnode = dnode->fwd;
    
    root_cp = root_cp->link;
  }

  Node * even = root;

  Node * odd = root->link;

  while (even->link != NULL && even->link->link != NULL)
  {
    even->link = even->link->link;

    even = even->link;
  }

  even->link =odd;

  if (len%2 != 0 && len > 1)
  {
    dnode = dnode->bwd;

    dnode->node->link = NULL;
  }

  while (dnode->bwd != NULL && dnode->bwd->bwd != NULL)
  {
    dnode->bwd->bwd->node->link = dnode->node;

    dnode = dnode->bwd->bwd;
  }

} //end of void method

void print_list(Node * root)
{
  while ( root != NULL)
  {
    printf("%p ",root);

    root = root->link;
  }
  
  printf("\n\n");
}

int main(void) 
{
  Node * zero = (Node *)malloc(sizeof(Node));

  Node * first = (Node *)malloc(sizeof(Node));

  Node * second = (Node *)malloc(sizeof(Node));

  Node * third = (Node *)malloc(sizeof(Node));

  Node * fourth = (Node *)malloc(sizeof(Node));

  Node * fifth = (Node *)malloc(sizeof(Node));

  zero->link = first;

  first->link = second;

  second->link = third;

  third->link = fourth;

  fourth->link = NULL;

  fifth->link = NULL;

  print_list(zero);
  
  even_odd_merge(zero);

  print_list(zero);


}
