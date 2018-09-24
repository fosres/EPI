#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  struct Node * link;

  int value;
} Node;

Node * add_two_numbers(Node * first, Node * second)
{
  int first_num = 0;

  while (first != NULL)
  {
    first_num *= 10;

    first_num += first->value;

    first = first->link;
  }

  int second_num = 0;

  while (second != NULL)
  {
    second_num *= 10;

    second_num += second->value;

    second = second->link;
  }

  int ans = first_num + second_num;

  
  Node * p = (Node *)malloc(sizeof(Node));

  Node * p_start = p;

  while (ans > 0)
  {
    p->value = ans % 10;

    ans /= 10;

    if ( ans > 0)
    {

    p->link = (Node *)malloc(sizeof(Node));

    p = p->link;
    }
  }

  

  return p_start;

}

void print_list(Node * root)
{
  while ( root != NULL)
  {
    printf("%d",root->value);

    root = root->link;
  }

  printf("\n\n");
}

int main(void) 
{
 Node * first = (Node *)malloc(sizeof(Node));

 first->value = 1;

 Node * second = (Node *)malloc(sizeof(Node));

 second->value = 2;

 Node * third = (Node *)malloc(sizeof(Node));

 third->value = 3;

 Node * fourth = (Node *)malloc(sizeof(Node));

 fourth->value = 4;

 first->link = second;

 second->link = NULL;

 third->link = fourth;

 fourth->link = NULL;

Node * ans = add_two_numbers(first,third);

print_list(ans);



}
