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
   r->val = s;

   r = r->link;

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

}

void free_sll(void * node)
{
    Node * q = NULL;

    while (node != NULL)
    {
        q = ((Node *)node)->link;

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


void sll_to_str(char ** des, Node * src)
{
    
    const int sll_size = size_of_sll(src);

    *des = (char *)malloc(sizeof(char)*sll_size);
   
    while (src != NULL)
    {
    
        strcat(*des,src->val);

        src = src->link;

    }

   free_arr(*des,sll_size); 

}

int main(int argc, char ** argv)
{
   Node * buf = (Node *)malloc(sizeof(Node));

   Node * head = buf;

   while (*++argv != NULL)
   {
   
        buf = insert_node(buf,*argv);
    
   }
#if 0
   char * str = NULL;

   sll_to_str(&str,head);

   double d = strtod(str,NULL);

   printf("%f\n",d);
#endif
   free_sll(head);
    
return 0;
}
