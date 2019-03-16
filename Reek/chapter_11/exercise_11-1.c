#include <stdio.h>
#include <stdlib.h>
//#include "alloc.h"


void * mycalloc(size_t size,size_t element_size)
{
 	void * new_arr = malloc(size * sizeof(element_size) );	
	
	


	return new_arr;

 	 
}

int main(void) 
{
   int i, n;
   int *a;

   printf("Number of elements to be entered:");
   scanf("%d",&n);

   a = (int*)mycalloc(n, sizeof(int));
   printf("Enter %d numbers:\n",n);
   for( i=0 ; i < n ; i++ ) {
      scanf("%d",&a[i]);
   }

   printf("The numbers entered are: ");
   for( i=0 ; i < n ; i++ ) {
      printf("%d ",a[i]);
   }
   free( a );
   
   return(0);

}
