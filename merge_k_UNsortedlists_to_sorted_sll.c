#if 0
  

Warning: Uses binary trees to rearrange linkages of original nodes. Not easy to understand or maintain.

#endif

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  struct Node * link;

  int value;
} Node;

typedef struct tree
{
  struct tree * left;

  struct tree * right;

  Node * node;
} tree;

void insert_node(tree ** root, Node * in)
{
  if (in == NULL) {return;}

  else if ( *root == NULL )
  {
    *root = (tree *)malloc(sizeof(tree));

    (*root)->left = NULL;

    (*root)->right = NULL;

    (*root)->node = in;

    return;
  }

  else if ( (*root)->node == NULL)
  { (*root)->node = in; return; }

  else if (in->value < ((*root)->node->value) )
  {
    insert_node(&((*root)->left),in);
  }

  else 
  {
    insert_node(&((*root)->right),in);
  }
}

void insert_sll(tree ** root, Node * in)
{
  if (in == NULL) {return;}

  insert_node(root,in);

  insert_sll(root,in->link);
}

Node * append_sll(Node * node, Node * in)
{
  if ( node == NULL) {return NULL;}

  if (in == NULL) {return node;}

  while (node->link != NULL)
  { node = node->link; } 


  node->link = in;

  node = node->link;

  node->link = NULL;

  return node;

}

Node * insert_value(Node * node, int in);

void tree_to_sll(tree * root, Node * node)
{
  if ( root != NULL && root->node != NULL)
  {
    tree_to_sll(root->left,node);

    node = append_sll(node,root->node);

    tree_to_sll(root->right,node);
  }
}

void free_tree(tree * root);
void free_sll(Node * root);
void in_order(tree * root);

Node * merge_lists(Node ** nap, Node ** nap_stop, tree * root, Node * ans)
{

  while ( nap < nap_stop )
  {
    insert_sll(&root,*nap);

    nap++;
  }

  tree_to_sll(root,ans);

  Node * second = ans->link;

  free(ans);

  return second;
}

void free_sll(Node * root)
{
  Node * q = NULL;

  if ( root != NULL)
  {
    q = root->link;

    free(root);

    root = q;

    free_sll(root);
  }
}

void free_tree(tree * root)
{
  if ( root != NULL)
  {
    free_tree(root->left);

    free_tree(root->right);
    
    free(root);
  }
}

Node * insert_value(Node * node, int in)
{
  if (node == NULL) 
  {printf("Error: The linked list is empty!\n\n"); return NULL;}

  else if ( node->link != NULL)
  { insert_value(node->link,in); }

  else
{

  node->link = (Node *)malloc(sizeof(Node));

  node = node->link;

  node->link = NULL;

  node->value = in;

  return node;
}
}

void free_node_arr(Node ** nap, Node ** nap_stop)
{
  if ( nap >= nap_stop)
  { return; }

  free_sll(*nap);

  free_node_arr(nap+1,nap_stop);

}

void in_order(tree * root)
{
  if ( root != NULL && root->node != NULL)
  {
    in_order(root->left);
    printf("%d ",root->node->value);
    in_order(root->right);
  }

}

void print_list(Node * root)
{
  if ( root != NULL)
  {
    printf("%d ",root->value);
    print_list(root->link);
  }
  else
  {
    puts("\n\n");
  }
}

void print_node_arr(Node ** nap, Node ** nap_stop)
{
  if ( nap >= nap_stop)
  { return; }

  print_list(*nap);

  print_node_arr(nap+1,nap_stop);
}

int main(void) 
{
  
  Node * first_sll = (Node *)malloc(sizeof(Node));

  Node * first_zero = first_sll;

  first_sll->link = NULL;

  first_sll->value = 3;

  first_sll = insert_value(first_sll,6);

  first_sll = insert_value(first_sll,12);

  first_sll = insert_value(first_sll,2);

  first_sll = insert_value(first_sll,7);

  first_sll = insert_value(first_sll,4);

  first_sll = insert_value(first_sll,1);

  first_sll = insert_value(first_sll,3);

  first_sll = insert_value(first_sll,5);

  Node * second_sll = (Node *)malloc(sizeof(Node));

  Node * second_zero = second_sll;

  second_sll->link = NULL;

  second_sll->value = 3;

  second_sll = insert_value(second_sll,5);

  second_sll = insert_value(second_sll,15);

  second_sll = insert_value(second_sll,13);

  second_sll = insert_value(second_sll,10);

  second_sll = insert_value(second_sll,7);

  second_sll = insert_value(second_sll,9);

  second_sll = insert_value(second_sll,4);

  second_sll = insert_value(second_sll,11);

  Node * third_sll = (Node *)malloc(sizeof(Node));

  Node * third_zero = third_sll;

  third_sll->link = NULL;

  third_sll->value = 3;

  third_sll = insert_value(third_sll,15);

  third_sll = insert_value(third_sll,16);

  third_sll = insert_value(third_sll,21);

  third_sll = insert_value(third_sll,34);

  third_sll = insert_value(third_sll,27);

  third_sll = insert_value(third_sll,19);

  third_sll = insert_value(third_sll,22);

  third_sll = insert_value(third_sll,27);

  Node * node_arr[3];

  node_arr[0] = first_zero;

  node_arr[1] = second_zero;

  node_arr[2] = third_zero;

  tree * root = (tree *)malloc(sizeof(tree));

  root->left = NULL; root->right = NULL;

  root->node = NULL;

  insert_sll(&root,node_arr[0]);

  insert_sll(&root,node_arr[1]);

  insert_sll(&root,node_arr[2]);

  Node * ans = (Node *)malloc(sizeof(Node));

  ans->link = NULL; ans->value = 0;


  ans = merge_lists(node_arr,node_arr+3,root,ans);

  print_list(ans);

  free_sll(ans);

  free_tree(root);

  return 0;
}



