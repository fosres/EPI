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
#if 0
	static char * t = "stag";
	static char * u = "is";
	static char * v = "cool";
	static char * w = "bro!";
	static char * x = NULL;
#endif
	char **arr = &s;

	*++arr = "swag";
	*++arr = "is";
	*++arr = "cool";
	*++arr = "bro!";
	*++arr = NULL;
	
	print_elements(&arr[0]);
	

	// If we were to make a double indirection (**), we would have to replace %s with a %c and the first chars in arrays [s,x] would be printed.


}
