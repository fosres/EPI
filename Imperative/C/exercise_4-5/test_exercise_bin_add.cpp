//clang 3.8.0

//C++ test file version

#include <iostream>
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <time.h>
using std::cout;
using std::endl;

void c_test_version() // slap the output of this method directly into the main method of your bin_add C source code file
{
    
    int x;
    int fr,fs;
    
    srand((unsigned)time(NULL));
    
    for (x=0; x < 10000; x++, fr=(float)rand()/RAND_MAX*10000,fs=(float)rand()/RAND_MAX*10000)
    {
        
        cout << "printf(\"%llu\\n\","<<"add("<<fr<<","<<fs<<")"<<");"<<endl;
        
        
    }
      
}


int main()
{
    c_test_version();
}
