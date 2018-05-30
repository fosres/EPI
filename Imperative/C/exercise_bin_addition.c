//exercise_bin_add.c

#include <stdio.h>

unsigned long long int add (unsigned long long int top, unsigned long long int bottom)
{
    
    int i = 0; int t, b; int c = 0;
    
    unsigned long long int sum = 0;
    
    while (i < 64)
    {
        t = top&1; b = bottom&1;
        
        if ( c^t^b == 0) // sum of 3 bits is 0 
        {
            
            sum |= ((c^t^b) << i);
            
            if ((c&t)||(c&b)||(t&b)) // two 1s
                c = 1;
            else
                c = 0;
        }
        
        else // sum of 3 bits is 1
        {
           sum |= ((c^t^b)<<i);
           
           if (c&t&b==1) c=1;
           else c=0;
        }
        
        i++; top>>=1; bottom>>=1;
        
        
        
    }
    
    return sum;
}
    
int main()
{
    
   printf("%d\n",3);
    
    
}
