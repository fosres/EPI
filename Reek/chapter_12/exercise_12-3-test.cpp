#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dll.h"
using std::cout;
using std::endl;

void exercise_12_3()
{

	srand(time(NULL));
	
	int i = 0;

	while ( i < 10000 )
	{
		cout << "dll_insert(head,tail," << (int)(rand()/(double)RAND_MAX*10000+0.5) << ");" << endl;
		
		i++;
		
	}
	
		cout << "print_values(head);" << endl;
}

int main()
{
	
	exercise_12_3();

}
