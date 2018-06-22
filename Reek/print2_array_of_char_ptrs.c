#include <stdio.h>

void print_elements(char **string)
{
	while ( *string != NULL )
	{
		printf("%s\n",*string++);
	}
}

int main()
{

	static char * s = "The";
	static char * t = "stag";
	static char * u = "is";
	static char * v = "cool";
	static char * w = "bro!";
	static char * x = NULL;
#if 0
	char **arr = &s;
	
	printf("%s\n",*arr++);
	printf("%s\n",*arr++);
	printf("%s\n",*arr++);
	printf("%s\n",*arr++);
	printf("%s\n",*arr++);
	printf("%s\n",*arr);
#endif
	print_elements(&s);
	

	// If we were to make a double indirection (**), we would have to replace %s with a %c and the first chars in arrays [s,x] would be printed.


}
