#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using std::cout;
using std::endl;

int main()
{
    int x;
    unsigned a;
    unsigned b;
    float fr;

    srand((unsigned)time(NULL));
    for(x=0;x<10000;x++)
    {
        a = (float)rand()/RAND_MAX * 100;
        b = (float)rand()/RAND_MAX * 100;
        cout << "printf(\"%u\\n\"," << "bit_multiply(" << a << "," << b << "));" << endl;

        
    }

    return(0);
}


