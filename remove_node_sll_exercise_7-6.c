#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  struct Node * link;
} Node;

int remove_node_sll(Node ** rootp, Node * node)
{

  if ( rootp == NULL )
  {
    printf("Error: Can't remove node from a\n\n");

    printf("linked list that doesn't exist\n\n");

    printf("is NULL!\n\n");

    return 0;
  }

  if ( node == NULL )
  {
    printf("Error: Illegal to try to remove node NULL\n\n");

    printf("from a linked list!\n\n");

    return 0;
  }

  while ( (*rootp) != NULL )
  {
    if ( (*rootp) == node )
    {
      (*rootp) = ( (*rootp)->link );

      return 1;
    }

    rootp = &((*rootp)->link);
  }
}

void print_sll(Node * first)
{
  if ( first == NULL)
  {
    return;
  }

  while (first != NULL)
  {
    printf("%p ",first);

    first = first->link;
  }

  printf("\n\n");
}

int main(void) {
  
  Node * first = (Node *)malloc(sizeof(Node));

  Node * second = (Node *)malloc(sizeof(Node));

  Node * third = (Node *)malloc(sizeof(Node));

  first->link = second;

  second->link = third;

  third->link = NULL;

  print_sll(first);

  remove_node_sll(&second,third);

  print_sll(first);


  return 0;
}
