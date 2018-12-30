#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <complex.h>

typedef struct Node
{
    struct Node * link;

    char * val;

}Node;

Node * insert_node(Node * r, char * s)
{
   r->link = (Node *)malloc(sizeof(Node));
   
   r = r->link;
   
   r->val = s;
   
   r->link = NULL;
   
   return r;

}

int size_of_sll(Node * r)
{
    int len = 0;

    while ( r != NULL )
    {
        len++;

        r = r->link;
    }
    
    return len;
}

void free_sll(Node * node)
{
    Node * q = NULL;

    while (node != NULL)
    {
        q = node->link;

        free(node);

        node = q;
    }

}

void free_arr(void * arr,const int SIZE)
{
    void * q = NULL;

    const void * arr_end = arr + SIZE;

    while (arr < arr_end)
    {
        q = arr+1; 
        
        free(arr);

        arr = q;
    
    }

}


void sll_to_str(char * des, Node * src)
{
    
    const int sll_size = size_of_sll(src);

    printf("%d\n",sll_size); 
    
    des = (char *)malloc(sizeof(char)*sll_size);
   
    while (src != NULL)
    {
    
        strcat(*des,src->val);

        src = src->link;

    }

   free_arr(des,sll_size); 

}

int main(int argc, char ** argv)
{
   Node * buf = (Node *)malloc(sizeof(Node));

   buf->val = NULL;

   buf->link = NULL;

   Node * head = buf;

   while (*++argv != NULL)
   {
   
        buf = insert_node(buf,*argv);
    
   }

   Node ** head_p = &head;

   (*head_p) = head->link;

   char * str = NULL;

   sll_to_str(str,head);
   
   double d = strtod(str,NULL);

//   printf("%f\n",d);
   
   free_sll(head);
    
return 0;
}
