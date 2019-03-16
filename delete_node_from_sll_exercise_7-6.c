#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  struct Node * link;

  int x;

} Node;

void delete_node (Node * rootp)
{
  if ( (rootp->link) == NULL )
  {

    printf("\nError: You cannot delete the tail of a node!\n\n");

    return;
  }

  *(rootp) = *((rootp)->link);
}

void print_sll(Node * root)
{
  while ( root != NULL )
  {
    printf("%p's int  is: %d ",root,root->x);

    root = root->link;
  }

  printf("\n");
}

int main(void) 
{

Node * first = (Node *)malloc(sizeof(Node));

first->x = 1;

Node * second = (Node *)malloc(sizeof(Node));

second->x = 2;

Node * third = (Node *)malloc(sizeof(Node));

third->x = 3;

Node * fourth = (Node *)malloc(sizeof(Node));

fourth->x = 4;

first->link = second;

second->link = third;

third->link = fourth;

fourth->link = NULL;

print_sll(first);

delete_node(fourth);

print_sll(first);

free(first);

free(second);

free(third);

free(fourth);
}
