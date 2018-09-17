#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  struct Node * link;

  struct Node * bwd;

} Node;

int remove_node_dll(Node ** rootp, Node * node)
{
  if ( rootp == NULL )
  { return 0; }

  while ( (*rootp) != NULL )
  {
    if ( (*rootp) == node )
    {
      
      if (node->link == NULL )
      {
        (*rootp)->bwd = NULL;

        (*rootp) = NULL;

        return 1;
      }
      

      Node * new_bwd = ( (*rootp)->bwd);

      (*rootp) = ((*rootp)->link);

      (*rootp)->bwd = new_bwd;

      return 1;
    }

    rootp = &( (*rootp)->link );
  }

  return 0;
}

void print_dll_fwd(Node * head)
{
  while (head != NULL )
  { 
    printf("%p ",head); 
  
    head = head->link; 
    
  }

  printf("\n\n");

}

void print_dll_bwd(Node * tail)
{
  while ( tail != NULL )
  { 
    printf("%p ",tail); 

    tail = tail->bwd;
  }
  printf("\n\n");
}


int main(void) 
{
  Node * first = (Node *)malloc(sizeof(Node));

  Node * second = (Node *)malloc(sizeof(Node));

  Node * third = (Node *)malloc(sizeof(Node));

  first->link = second;

  first->bwd = NULL;

  second->link = third;

  second->bwd = first;

  third->link = NULL;

  third->bwd = second;

  print_dll_fwd(first);

  print_dll_bwd(third);

  printf("%d\n\n",remove_node_dll(&first,first));

  print_dll_fwd(first);

  print_dll_bwd(third);

  free(first);

  free(second);

  free(third);

}
