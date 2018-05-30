//clang 3.8.0

//C++ test file version

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
    int fr,fs;
    
    srand((unsigned)time(NULL));
    
    for (x=0; x < INT_MAX; x++, fr=(float)rand()/RAND_MAX*INT_MAX,fs=(float)rand()/RAND_MAX*INT_MAX)
    {
        
        cout << "printf(\"%llu\\n\","<<fr<<"+"<<fs<<");"<<endl;
        printf("\n");
        
        
    }
}
