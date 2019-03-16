#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  struct Node * link;

  int value;
} Node;


Node * add_two_numbers(Node * first, Node * second)
{
  int carry = 0;

  Node * ans = (Node *)malloc(sizeof(Node));

  Node * ans_zero = ans;

while(1)
{
  if (first == NULL && second == NULL)
  {
    if ( carry != 0)
    {
      ans->value = carry;

      ans->link = (Node *)malloc(sizeof(Node));

      ans = ans->link;

      ans->link = NULL;

      return ans_zero;
    }

    ans->link = NULL;

    return ans_zero;
  }

  else if (first == NULL)
  {
      ans->value = (carry+second->value)%10;

      carry = (carry+second->value)/10;

      ans->link = (Node *)malloc(sizeof(Node));

      ans = ans->link; second = second->link;
  }

  else if (second == NULL)
  {
    ans->value = (carry+first->value)%10;

    carry = (carry+first->value)/10;

    ans->link = (Node *)malloc(sizeof(Node));

    ans = ans->link; first = first->link;
  }

  else
  {
    ans->value = (carry+(first->value)+(second->value))%10;

      carry = (carry+(first->value)+(second->value))/10;

      ans->link = (Node *)malloc(sizeof(Node));

      ans = ans->link; 
      
      first = first->link;
      
      second = second->link;
  }

} // end of while loop

}

void print_int(Node * root)
{
  while ( root->link != NULL)
  {
    printf("%d ",root->value);

    root = root->link;
  }
  printf("\n\n");
}

int main(void) {

  Node * first = (Node *)malloc(sizeof(Node));

  first->value = 2;

  Node * second = (Node *)malloc(sizeof(Node));

  second->value = 9;

  Node * third = (Node *)malloc(sizeof(Node));

  third->value = 9;

  Node * fourth = (Node *)malloc(sizeof(Node));

  fourth->value = 3;

  Node * fifth = (Node *)malloc(sizeof(Node));

  fifth->value = 6;

  Node * sixth = (Node *)malloc(sizeof(Node));

  sixth->value = 9;

  first->link = second;

  second->link = third;

  third->link = NULL;

  fourth->link = fifth;

  fifth->link = sixth;

  sixth->link = NULL;

  Node * ans = add_two_numbers(second,fifth);

  print_int(ans);

  return 0;
}
