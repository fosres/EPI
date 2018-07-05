#include <stdio.h>
#include <ctype.h>


void tabify()
{

	int IN_SPACE = 0;
	int c;

	while ((c = getchar()) != EOF )
	{
		if (!isspace(c) && IN_SPACE)
		{ putchar(' ');putchar(' ');putchar(' ');putchar(' ');
		  putchar(c);
		}
		
		else if (isspace(c) && !IN_SPACE)
		{ putchar(c); IN_SPACE = 1; }

		else if (isspace(c) && IN_SPACE )

	}

}
