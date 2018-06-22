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
	static char ** arr_p = &s;
	*++arr_p = "stag";
	*++arr_p = "is";
	*++arr_p = "cool";
	*++arr_p = "bro!";
	*++arr_p = NULL;
	print_elements(&arr_p[0]);
	

	// If we were to make a double indirection (**), we would have to replace %s with a %c and the first chars in arrays [s,x] would be printed.


}
