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
	printf("%d\n",check_par("((())"));
	printf("%d\n",check_par("((()))"));
	printf("%d\n",check_par("(((())))(())(((())))()"));
	printf("%d\n",check_par("7 + (6 × 25 + 3)"));
	printf("%d\n",check_par("(x^2+y^2)(x+v)"));
	putchar(' ');
	printf("%d\n",check_par("[(2x+1)+(2a+1)][(3x-1)+(3a-1)]"));
}
