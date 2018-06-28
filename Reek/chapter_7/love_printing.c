#include <stdio.h>
#include "printf.h"

int main()
{

	myprintf("The cheese is delicious\n");
	myprintf("The hot dog costs %f\n",25.35);
	myprintf("My first and last letters are %c and %c.\nMy name is %s.\nMy ID number is %d.\nMy bank account balance is %f.\n",'T','S',"John Bundenseen",321363,113783.352);
}
