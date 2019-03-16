#include <stdio.h>
#include <string.h>
#include <ctype.h>

void strupper(char *s)
{

	while ( *s != '\0') 
	{

		if (isalpha(*s))
		{
			*s = toupper(*s);	
		}

		s++;
	}

}


int prepare_key(char * key)
{

	char mod[1000]; char * mod_p = mod; char * key_zero = key;

	strupper(key);

	if (strlen(key) == 0)
	{ return 0;}

	while (*key != '\0' )
	{
		
		if (!isupper(*key))
		{ return 0;}

		if (strchr(mod,*key) == NULL )
		{ *mod_p++ = *key; }

		key++;

	}

	char ALPHABET[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	char * a_p = ALPHABET;

	while (*a_p != '\0' )
	{
		if (strchr(mod,*a_p) == NULL )
		{ *mod_p++ = *a_p;}
		a_p++;

	}

	mod_p = &mod[0];

	while ((*key_zero++ = *mod_p++) != '\0')
		;

	*key_zero = '\0';

	return 1;

}

int main()
{

	static char s[1000] = "TRAILBLAZERS";

	prepare_key(s);

	printf("%s\n",s);

	s[0] = '\0';

	strcat(s,"Swiss");

	prepare_key(s);

	s[0] = '\0';

	strcat(s,"988theTL");

	printf("%d\n",prepare_key(s));

}

