#include <stdio.h>
#include <stdlib.h>

#define item int
typedef struct Node
{
  struct Node * link;
  
  item x;

} Node;

item print_list(Node * rootp)
{
  while ( rootp != NULL )
  {
    printf("%d ",rootp->x);

    rootp = rootp->link;
  }
}

Node * reverse_sublist(Node * rootp, int s, int f)
{
  Node * list_c = rootp; int len = 0;

  Node * first = rootp;

  while ( list_c != NULL )
  {
    len++; list_c = list_c->link;
  }

  len++; // account for NULL

  Node * node_arr[len];

  Node ** node_arr_p = &node_arr[0];

  list_c = rootp;

  while (list_c != NULL )
  {
    *node_arr_p++ = list_c; 

    list_c = list_c->link;

  }

  *node_arr_p = NULL;

  list_c = rootp; 
  
  node_arr_p = &node_arr[0];

  while ( list_c->x != s )
  {
    node_arr_p++;

    list_c = list_c->link;

  }

  if ( list_c != first )
  {

    Node * node_s = *node_arr_p;

    Node * before_sub = ( *(node_arr_p - 1) );

    node_arr_p++;

    while ( (*node_arr_p)->x != f)
    {
      (*node_arr_p)->link = (*(node_arr_p-1));

      node_arr_p++;
    }

    (*node_arr_p)->link = (*(node_arr_p-1) ); // link node with f to one before it

    before_sub->link = *node_arr_p;

    node_s->link = *(++node_arr_p);
  }
    
    else // list_c == first
    {
      Node * node_s = *node_arr_p;

      node_arr_p++;

      while ( (*node_arr_p)->x != f)
      {
        (*(node_arr_p))->link = (*(node_arr_p-1));

        node_arr_p++;
      }

      (*node_arr_p)->link = (*(node_arr_p-1));

      rootp = *node_arr_p;

      node_s->link = *(++node_arr_p);

    }

    return rootp;

  }

int main(void) {
  Node * first = (Node *)malloc(sizeof(Node));

  first->x = 11;

  Node * second = (Node *)malloc(sizeof(Node));

  second->x = 7;

  Node * third = (Node *)malloc(sizeof(Node));

  third->x = 5;

  Node * fourth = (Node *)malloc(sizeof(Node));

  fourth->x = 3;

  Node * fifth = (Node *)malloc(sizeof(Node));

  fifth->x = 2;

  first->link = second;

  second->link = third;

  third->link = fourth;

  fourth->link = fifth;

  fifth->link = NULL;

  Node * ans = reverse_sublist(first,11,2);

  print_list(ans);

  return 0;
}
