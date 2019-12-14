#include <stdio.h>

int main()
{
	printf("static char q[] = {");
	
	char  * q_p = q;

	while ( *q_p != 0x0 )
	{
		printf("0x%02x,",*q_p);
		
		q_p++;
	}

	printf("0x0};\n");

	printf("%s",q);	
}
