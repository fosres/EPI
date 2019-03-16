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

void print_sll(Node * r)
{
    while (r != NULL)
    {
        printf("%s ",r->val);

        r = r->link;
    }

    printf("\n");

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


void sll_to_str(char ** des, Node * src)
{
    
    const int sll_size = size_of_sll(src);
    
    *des = (char *)malloc(sizeof(char)*sll_size);
   
    while (src != NULL)
    {
    
        strcat(*des,src->val);

        strcat(*des,"\0");

        src = src->link;

    }

}

void infix_to_postfix(char *s)
{

    while (!isdigit(*s) && *s != '(')
    {    s++; }

    while (*s != '\0')
    {
        switch (*s)
        {
            case ')':
            {
                
                break;
            }

            case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
            {


                break;
            }

            case '+': case '-': case '*': case '/': case '%':
            {


                break;
            }

            case '(':
            {


                break;
            }

            default:
            {
                printf("Error: %c\n",*s);

                exit(EXIT_FAILURE);

                break;
            }


        }

    }
    

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

//   buf->link = NULL;

   Node * head_cp = head;
   
   Node ** head_p = &head;

   (*head_p) = head->link;

   free(head_cp);

   print_sll(head);

   char * str = (char *)malloc(sizeof(char)*size_of_sll(head));

   sll_to_str(&str,head);

   printf("%s\n",str);
   
   double d = strtod(str,NULL);

   free_arr(str,size_of_sll(head)); 

   printf("%f\n",d);
   
   free_sll(head);
    
return 0;
}
