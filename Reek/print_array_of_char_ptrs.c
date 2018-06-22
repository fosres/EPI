#include <stdio.h>

int main()
{

	static char * s = "The";
	static char * t = "stag";
	static char * u = "is";
	static char * v = "cool";

	static char * w = "bro!";
	char **arr = &s;
	
	printf("%s\n",*arr++);
	printf("%s\n",*arr++);
	printf("%s\n",*arr++);
	printf("%s\n",*arr++);
	printf("%s\n",*arr);

	// If we were to make a double indirection (**), we would have to replace %s with a %c and the first chars in arrays [s,v] would be printed.


}
