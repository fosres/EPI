#include <stdio.h>
#include <string.h>

int * search_for_char(char ** s, const char key)
{
	
	int pos_arr[strlen(s)]; int * p_zero = pos_arr; 
	
	int * p = pos_arr; 

	char ** s_zero = s;

	while (*s != NULL )
	{
		
		if ( strchr(*s,key) != NULL )
		{ *p++ = (int)(strchr(*s,key) - *s ); }
		else
		{ *p++ = -1; }
		s++;
	}


	return p_zero;

}

void print_elements(char **string)
{
	while ( *string != NULL )
	{
		printf("%s\n",*string++);
	}
}

int main()
{

	static char * s = "The";
	
	char ** arr = &s; 
	
	char ** arr_p = arr; 

	*++arr = "swag";
	*++arr = "is";
	*++arr = "cool";
	*++arr = "bro!";
	*++arr = "Yay!";
	*++arr = NULL;

	print_elements(arr_p);
	
	int * pos = search_for_char(arr_p,'a');

	for ( int i = 0; i < strlen(arr_p); i++)
		printf("arr[%d] has key at: %d\n",i,*pos++);
	// If we were to make a double indirection (**), we would have to replace %s with a %c and the first chars in arrays [s,x] would be printed.


}
