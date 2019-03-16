#include <stdio.h>

int check_par(char *s)
{
	int PARS_PAIRED;
	int BRACKETS_PAIRED;
	int CURLYS_PAIRED;
	char * s_zero = s;
	char par[1000];
	char brackets[1000];
	char curlys[1000];

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
	{ PARS_PAIRED = 1; }
	else 
	{ PARS_PAIRED = 0; }

	s = s_zero;
	
	char * brackets_p = (&brackets[0]-1);

	while (*s != '\0')
	{
		if (*s == '[')
		{ ++brackets_p; }
		else if (*s == ']')
		{ --brackets_p; }
		
		s++;

	}

	if ( brackets_p == (&brackets[0]-1))
	{ BRACKETS_PAIRED = 1; }
	else 
	{ BRACKETS_PAIRED = 0; }

	s = s_zero;

	char * curlys_p = (&curlys[0]-1);

	while (*s != '\0')
	{
		if (*s == '{')
		{ ++curlys_p; }
		else if (*s == '}')
		{ --curlys_p; }
		
		s++;

	}

	if ( curlys_p == (&curlys[0]-1))
	{ CURLYS_PAIRED = 1; }
	else 
	{ CURLYS_PAIRED = 0; }

	return (PARS_PAIRED && BRACKETS_PAIRED && CURLYS_PAIRED);

}

int main()
{

#if 0
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
#endif
	printf("%d\n",check_par("[()[]{()()}]"));
	printf("%d\n",check_par("[()[]{()()}"));
	printf("%d\n",check_par("()[]{()()}"));
	printf("%d\n",check_par("{)"));
	printf("%d\n",check_par("([]){()}"));
	printf("%d\n",check_par("[()[]{()()"));
}

