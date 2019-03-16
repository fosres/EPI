#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
using std::cout;
using std::endl;

int main()
{
    unsigned x,y;
    float fr1,fr2;

    srand((unsigned)time(NULL));
    
    for( int i= 0 ; i < 10000 ; i++)
    {
        fr1 = (float)rand()/RAND_MAX;
        fr2 = (float)rand()/RAND_MAX;
        x = fr1*UINT_MAX;
        y = fr2*UINT_MAX;
        
        cout<<"printf(\"%u\\n\",quotient("<<x<<","<<y<<"));"<<endl;
    }

    return(0);
}

