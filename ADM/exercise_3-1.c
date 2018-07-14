#include <stdio.h>

int check_par(char *s)
{

	char par[1000];

	char * par_p = (&par[0]-1);

	while (*s != '\0')
	{
		if (*s == '(')
		{ ++par_p; }
		else if (*s == ')')
		{ --par_p; }
		
		s++;

	}

	if ( par_p == (&par[0]-1))
	{ return 1; }
	return 0;
}

int main()
{
	printf("%d\n",check_par("()"));
	printf("%d\n",check_par("((())())()"));
	printf("%d\n",check_par(""));
	printf("%d\n",check_par("((("));
}
