#include <stdio.h>
#include <stdlib.h>


int main(void) 
{
   int *a = (int *)calloc(1, sizeof(int));

   int size = sizeof(int);

   int i = 0;

   printf("Enter numbers:\n");

   while ( scanf("%d",&a[i]), a[i] != -1 ) 
   {
	a = (int *)realloc(a,size += sizeof(int));
	i++;
   }

   i = 0;

   printf("\n");

	while ( a[i] != -1 ) printf("%d\n",a[i++]);

   free( a );
  
   return(0);

}

