#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool isValid(char * s) {
	
	const size_t slen = strlen(s);

	char stack[slen]; 

	char * stack_p  = stack-1;

	char * s_p = s;

	while (*s_p != 0x0) {
		
		switch(*s_p) {

			case '{':
				{
					
					*++stack_p = '{';

					break;

				}

			case '}':
				{
					if ( *stack_p != '{' ) {
						
						return 0;
					}

					stack_p--;

					break;
				}

			case '(':
				{
					
					*++stack_p = '(';

					break;

				}

			case ')':
				{
					if ( *stack_p != '(' ) {
						
						return 0;
					}

					stack_p--;

					break;
				}

			case '[':
				{
					
					*++stack_p = '[';

					break;

				}

			case ']':
				{
					if ( *stack_p != '[' ) {
						
						return 0;
					}

					stack_p--;

					break;
				}
			default:{break;}
		}

		s_p++;
	}
	
	bool ans = (stack_p < stack)?1:0;

	return ans;

}

int main(int argc,char**argv) {
	
	printf("%d\n",isValid(argv[1]));

	return 0;
}

