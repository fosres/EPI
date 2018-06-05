// exercise_3-3.c

#include <stdio.h>
#include <string.h>

char * expand(char * s1, char * s2)
{

	char c; char * s1_zero = s1; char * s2_zero = s2;

	while (*s1 != '\0')
	{

		
		if 	(  // PARADOX: making sure first and last chars are not equal to '-' yet ensuring *s1 == '-' split the three conditionals into their own if-else-if-else statements
		
		     *s1 != *s1_zero

		     && *s1 != *(s1_zero + strlen(s1_zero) - 1)
		     && *s1 == '-'

		   	)
		{

			for ( c = *(s1-1); c <= *(s1 + 1); c++)
				*s2++ = c;

		}
		else // Do nothing
		{
		}

		s1++;

	}

	return s2_zero;

}

int main()
{
	char input[1000] = "a-l-r-0-9-d-m";	
	char output[1000];	
	printf("%s\n",expand(input,output));

}

