//clang 3.8.0

#include <iostream>
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <time.h>
using std::cout;
using std::endl;

int main()
{
    int x;
    float fr,fs;
    
    srand((unsigned)time(NULL));
    
    for (x=0; x < INT_MAX; x++, fr=(float)rand()/RAND_MAX,fs=(float)rand()/RAND_MAX)
    {
        
        cout << "printf(\"%llu\\n\","<<fr<<"+"<<fs<<")"<<endl;
        printf("\n");
        
        
    }
}
