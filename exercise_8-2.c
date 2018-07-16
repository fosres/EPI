#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int eval_RPN(char * s)
{
	char *s_digits = s;

	while (*s_digits != '\0' && isdigit(*s_digits++));

	if (*s_digits == '\0')
	{ return atoi(s);}
	
	return EOF;
}

int main()
{
	
	static char s[1000] = "5325";

	printf("%d\n",eval_RPN(s));	

}

