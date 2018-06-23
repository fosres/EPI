#ifndef __STDIO_H__
#define __STDIO_H__
#include <stdio.h>

int mystrlen(char const * s)
{
  int len = 0; char *s_p = (char *)s;

  while (*s_p++ != '\0' )
  {
    len++;
  }
  return len;
}

char * mystrstr(char const *source, char const *target)
{
	
	char * p1 = (char *)source;

	while (*p1 != '\0' )
	{	
		char *p1_start_index = p1; char * p2 = (char *)target;

		while (*p1 != '\0' && *p2 != '\0' && *p1 == *p2 )
		{ p1++; p2++; }

		if ( *p2 == '\0' )
			return p1_start_index;
		p1 = ++p1_start_index;

	}

	return NULL;

}

int del_substr(char *str, char *substr)
{
	
	if (mystrstr(str,substr)==NULL)
		return 0;

	char * cp_i = (mystrstr(str,substr) + mystrlen(substr));
	
	char * src_i = mystrstr(str,substr);

	while (*cp_i != '\0' )
	{ *src_i++ = *cp_i++; }

	*src_i = '\0';

	return 1;

}

#if 0
int main(void)
{
  char a[1000] = "Slapstick Comedy";
  char b[1000] = "S";

  printf("%s\n",mystrstr(a,b));
  
  int len = mystrlen(a);

  printf("%d\n",len);
  del_substr(a,b);
  printf("%s\n",a);
}
#endif

#endif // __STDIO_H__
