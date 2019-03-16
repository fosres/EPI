// exercise_4-6.c

#include <stdio.h>

unsigned quotient (unsigned x, unsigned y)
{
    int q = 0;
    
    while (x >= y)
    {
        q++;
        
        x = x - y;
        
        
    }
    
    return q;
}

int main()
{
    
    printf("%u\n",quotient(1,6));
    
}
