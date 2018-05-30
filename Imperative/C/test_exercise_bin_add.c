//clang 3.8.0

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int x;
    float fr,fs;
    
    srand((unsigned)time(NULL));
    
    for (x=0; x < INT_MAX; x++, fr=(float)rand()/RAND_MAX,fs=(float)rand()/RAND_MAX)
    {
        
        printf("printf(\"%llu\\n\",fr)");
        printf("\n");
        
        
    }
}
