#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "stack.h"

#define SIZE 1000

static int stack[SIZE];

static int * stack_p = (&stack[0] - 1);

void push(STACK_TYPE in)
{ *++stack_p = in; }

STACK_TYPE pop()
{ return *stack_p--;}

int myatoi(char s[])
{
    int IS_NEG = 0; int result = 0;
    
    for ( int i = 0; i < strlen(s); i++ )
    {
        if (s[i] == '-')
        { IS_NEG = 1; continue; }
        
        result = (result*10) + (s[i] - '0');
    }
    
    if (IS_NEG)
    { return -result;}
    
    return result;
}

STACK_TYPE eval_RPN(char *s)
{
	char * s_p = s; char number[strlen(s)]; char * num_p = &number[0];

	int IS_NEG = 0;

	while (*s_p != '\0')
	{
		switch(*s_p)
		{
			case '+':
			{ push(pop() + pop()); break; }

			case '*':
			{  push(pop() * pop()); break; }
			
			case '-':
			{ 
				if (*(s_p+1) == ','||*(s_p+1) == '\0')
				{
				int op2 = pop();

				push(pop() - op2);
				}
				else
				{ IS_NEG = 1;}

				break;
			}

			case '/':
			{
				int op2 = pop();

				push(pop()/op2);

				break;
			}
			
			case ',':
			{ break; }
			default:
			{ 
				while (isdigit(*s_p)) { *num_p++ = *s_p++; }

				*num_p = '\0';
				
				if (IS_NEG)
				{ push(-atoi(number)); IS_NEG = 0;}
				else
				{ push(atoi(number)); }

				num_p = &number[0];

				break;

			}
		}

		s_p++;
	
	}

	stack_p = (&stack[0] - 1);
	
	return stack[0];
}

int main()
{
	printf("%d\n",eval_RPN("-36,-36,+,-10,+"));
	printf("%d\n",eval_RPN("18,3,/,6,+"));
	
	printf("%d\n",eval_RPN("3,4,+,2,*,1,+"));

	printf("%d\n",eval_RPN("-641,6,/,28,/"));

	printf("%d\n",eval_RPN("3252"));

	printf("%d\n",eval_RPN("-10"));

	printf("%d\n",eval_RPN("10,-10,-,-10,-,-10,-"));

	printf("%d\n",eval_RPN("32,-32,-,32,-,-32,-,32,-,32,+,64,-"));

	printf("%d\n",eval_RPN("-9999"));
}
