#include <stdio.h>
#include <string.h>
#include <ctype.h>

void reverse(char *s);

void strlower(char *s)
{
	
	char *s_p = s;

	while (*s_p != '\0')
	{
		*s_p = tolower((int)*s_p);

		s_p++;
	}

}

int palindrome(char *string)
{

	char s_rev[strlen(string)];

	strcpy(s_rev,string);

	reverse(s_rev);
	
	return ((int)(strstr(string,s_rev)-&string[0])==0);

}

void reverse(char *s)
{

	for (int i = 0, j = strlen(s)-1;i < j; i++,j--)
	{

		char temp = s[i];

		s[i] = s[j];

		s[j] = temp;

	}

}

void clear (char *s)
{
	s[0] = '\0';
}

int main()
{

	static char s[1000] = "1";


	s[0]=  '\0';

	strcat(s,"ALPHA");

	strlower(s);

	printf("%s\n",s);

	printf("%d\n",palindrome(s));

	s[0] = '\0';

	strcat(s,"RACECAR");

	printf("%d\n",palindrome(s));

	s[0] = '\0';

	strcat(s,"RaCeCaR");

	s[0] = '\0';
	
	strcat(s,"The cheese");
	
	printf("%d\n",palindrome(s));

	s[0] = '\0';

	strcat(s,"T T");

	printf("%d\n",palindrome(s));
}
