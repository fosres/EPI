#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  struct Node * link;

  int x;
} Node;

void delete_duplicate(Node * root)
{
  if ( root == NULL )
  { return; }

  while ( root != NULL && root->link != NULL )
  {
    if ( (root->x) == ( (root->link)->x))
    {
      (*root) = *(root->link);
    }

    root = root->link;
  }

}

void print_sll(Node * root)
{
  while ( root != NULL )
  {
    printf("%d ",root->x);

    root = root->link;
  }
}

int main(void) 
{
  Node * first = (Node *)malloc(sizeof(Node));

  first->x = 2;

  Node * second = (Node *)malloc(sizeof(Node));  

  second->x = 2;

  Node * third = (Node *)malloc(sizeof(Node));

  third->x = 3;

  Node * fourth = (Node *)malloc(sizeof(Node));
  
  fourth->x = 3;

  Node * fifth = (Node *)malloc(sizeof(Node));

  fifth->x = 4;

  Node * sixth = (Node *)malloc(sizeof(Node));

  sixth->x = 4;

  Node * seventh = (Node *)malloc(sizeof(Node));

  seventh->x = 5;

  Node * eighth = (Node *)malloc(sizeof(Node));

  eighth->x = 5;

  Node * ninth = (Node *)malloc(sizeof(Node));

  ninth->x = 7;

  Node * tenth = (Node *)malloc(sizeof(Node));

  tenth->x = 7;

  Node * eleventh = (Node *)malloc(sizeof(Node));

  eleventh->x = 11;

  Node * twelveth = (Node *)malloc(sizeof(Node));

  twelveth->x = 11;

  first->link = second;

  second->link = third;

  third->link = fourth;

  fourth->link = fifth;

  fifth->link = sixth;

  sixth->link = seventh;

  seventh->link = eighth;

  eighth->link = ninth;

  ninth->link = tenth;

  tenth->link = eleventh;

  eleventh->link = twelveth;

  delete_duplicate(first);

  print_sll(first);

  delete_duplicate(first);

  print_sll(first);

  delete_duplicate(NULL);

  free(first);

  free(second);

  free(third);

  free(fourth);

  free(fifth);

  free(sixth);

  free(seventh);

  free(eighth);

  free(ninth);

  free(tenth);

  free(eleventh);
  
  free(twelveth);


}
