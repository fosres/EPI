#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <float.h>

#define MAX_LENGTH 1000

void reverse (char *s)
{
	char temp;	
	
	for ( int i = 0, j = strlen(s)-1; i < j; i++, j--)
	{
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	}
}


char * lltoa(long long int n)
{
  	static char s[MAX_LENGTH];

	long long int i, sign;

	if ((sign = n) < 0) /* record sign */
		n = -n;	    /* make n positive by n =-n */
	i = 0;
	do 		/* generate digits in reverse order */
	{
		s[i++] = lldiv(n,10).rem + '0'; /* get next digit with n % 10 + '0'; */

	} while (n = lldiv(n,10).quot, n > 0);       /* delete it with while ( (n /= 10) > 0 )*/
	
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);

	return s;
}

double nround(double input, double power)
{
	
	double marge = pow(10,power);

	double up = input * marge;

	double result = ((double)(llround(up)))/marge;

	return result;

}

// ftoa rounds accurately up to 15 digits
void ftoa(const double input, double power) // pow is the '*' in "%.*f"
{
  
  const double in = nround(input,power); 

  char a[MAX_LENGTH] = "\0";

  long long int f_to_i = (long long int)(in); 
  
  strcat(a,lltoa(f_to_i)); strcat(a,".");

  double integral[1000] = {0};

  double fraction = modf(in,integral); /* stores fractional part of input */

  char non_zero_mantissa[1000] = "\0"; /* stores non-zero digits in mantissa after leading zeros following decimal point */

  strcat(non_zero_mantissa,lltoa(llround(fraction*pow(10,power))));


  int i = strlen(non_zero_mantissa);

  while ( i++ < power )
  {
	strcat(a,"0");

  }

  strcat(a,non_zero_mantissa);

  char * a_p = a;

  while (*a_p != '\0')
  {
	putchar(*a_p++);
  }
}


int myprintf(char const * s)
{
  while (*s != '\0')
    putchar(*s++);
  return 1;
}

//#if 0
int main(void) 
{
#if 0
	ftoa(3.000005,5);
	putchar('\n');
#endif
	ftoa(3.6666666666666666,15);
	putchar('\n');
	ftoa(3.15,1);
	putchar('\n');
	ftoa(3.0000009,6);
	putchar('\n');
	ftoa(3.4545,3);
	putchar('\n');
	ftoa(3.0000000000000009,15);
	putchar('\n');
	ftoa(3.0000000000000099,15);
	putchar('\n');
	ftoa(1.9999999e5,1);


}
//#endif
