#include <stdio.h>
#include <string.h>
#include <ctype.h>

void strlower(char *s)
{
	char *s_p = s;

	while (*s_p != '\0')
	{
		*s_p = tolower((int)*s_p);

		s_p++;
	}


	


}

int count_the(char *s)
{

	strlower(s); int c = 0;

	while (strstr(s,"the") != NULL)
	{
		c++;

		*strstr(s,"the") = 'x';
	}

	return c;
}

int main()
{
	static char s[1000] = "thethethe";	
	
	printf("%d\n",count_the(s));

	s[0] = '\0';

	strcat(s,"theheethtthe"); //should be 2

	printf("%d\n",count_the(s));

}
