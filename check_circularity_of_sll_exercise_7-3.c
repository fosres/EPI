#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  struct Node * link;

  int x;

} Node;

typedef struct tree
{
  struct tree * left;

  struct tree * right;

  Node * node;
} tree;

void free_tree(tree * root)
{
  if ( root != NULL)
  {
    
    free_tree(root->left);
    
    free_tree(root->right);
    
    free(root);
    
  }
}
int insert(tree ** rootp, Node * in)
{
  
  if ( (*rootp) == NULL )
  {
    (*rootp) = (tree *)malloc(sizeof(tree));

    (*rootp)->left = NULL; (*rootp)->right = NULL; (*rootp)->node = in;
    
    return 0; // No circularity

  }

  else if ( (*rootp)->node == in ) 
  {
    return 1;
  }

  else if ( in < (*rootp)->node )
  {
    insert(&((*rootp)->left),in);
  }

  else // (in >= (*rootp)->node )
  {
    insert(&((*rootp)->right),in);
  }

} // end of insert function

int check_circularity(Node * input, tree * root)
{
  if ( input == NULL || input->link == NULL )
  {
    return 0;
  }

  else if (insert(&root,input) == 1 ) // adds in into bin tree
  {
    return 1;
  }
  check_circularity(input->link,root);

}

Node * check_circ(Node * input)
{

  tree * root = (tree *)malloc(sizeof(tree));
  
  root->left = NULL; root->right = NULL;
  
  root->node = NULL;

  if ( check_circularity(input,root) == 0)
  {
    return NULL;
  }

  free(root);

  return input;
}



int main(void) 
{
  
  Node * head = (Node *)malloc(sizeof(Node));

  head->x = 3;

  Node * second = (Node *)malloc(sizeof(Node));

  second->x = 5;

  Node * third = (Node *)malloc(sizeof(Node));

  third->x = 6;

  Node * fourth = (Node *)malloc(sizeof(Node));

  fourth->x = 8;

  head->link = second;

  second->link = third;

  third->link = fourth;

  fourth->link = NULL;

  tree * root = (tree *)malloc(sizeof(tree));

  root->left = NULL; root->right = NULL;

  root->node = NULL;

  printf("%p\n",fourth);

  printf("%d\n",check_circularity(fourth,root));

  free(head);

  free(second);

  free(third);

  free(fourth);
  
  free_tree(root);
  
  return 0;

}
