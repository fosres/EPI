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
// replace '/' with a better division function
	return result;

}


char * ftoa(const double input, const double power) // pow is the '*' in "%.*f"
{
  
  const double in = nround(input,power); 

  static char a[MAX_LENGTH];

  long long int f_to_i = (long long int)(in); 
  
  strcat(a,lltoa(f_to_i)); strcat(a,".");

  static double integral[1000];

  double fraction = modf(in,integral); /* stores fractional part of input */

#if 0

	Convert mantissa stored in fraction into a long long int by first multiplying fraction by pow(10,power) and then applying strcat(a,lltoa((long long int)(fraction*pow(10,power))));

	No need for while ( i < power ) loop any longer

#endif


  strcat(a,lltoa(llround(fraction*pow(10,power))));

#if 0
  
  static int i; double divisor = 0.1;

  while ( i < power ) 	/* by default %f in printf is six decimal digits precise  */
  {
	strcat(a,lltoa(((long long int)(fraction *= 10))%10));

	/*divisor /= 10;*/ i++;
  }

#endif


  return a;
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
	printf("%s\n",ftoa(3.15,0));
}
//#endif
