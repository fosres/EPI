#include <stdio.h>
#include <stdbool.h>

bool parity(long long int x)
{
    
   int b = 0;
    
   while (x != 0)
   {
       
      x&=(x-1);
       
      b++;
       
       
   }
    
    return !(b%2==0);
    
}

int main()
{
    
    printf("%d\n",parity(07777));
    
    
}
