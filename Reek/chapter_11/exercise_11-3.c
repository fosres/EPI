#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * dyn_cpy(char * s)
{

	char * s_dyn = (char *)calloc(strlen(s),sizeof(char)*strlen(s));

	char * s_dyn_zero = s_dyn;
	
	while ( (*s_dyn++ = *s++) != '\0')
		;

	return s_dyn_zero;

	free(s_dyn);

}

int main()
{
	char * s = "The swag monster is down. We better figure out a way to take him out.";

	char * t = dyn_cpy(s);

	printf("%s\n",t);
}
