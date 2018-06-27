#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <float.h>
#include <assert.h>

#define MAX_LENGTH 1000

void reverse (char *s) {
	char temp;	
	
	for ( int i = 0, j = strlen(s)-1; i < j; i++, j--)
	{
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	}
}


char * printd(long long int n)
{
  
  static char d[1000];
  static char abs[1000];
  static char * abs_p = abs;
  static int sign;
  if ( n < 0 )
  {
    *d = ('-');
    n = -n;
  }

  while ( lldiv(n,10).quot != 0)
  {
    *abs_p++ = (lldiv(n,10).rem+'0');

    n = (lldiv(n,10).quot);

  }

  reverse(abs);
  strcat(d,abs);

  return d;
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

char * lltoa2(long long int n)
{
  
  static char d[MAX_LENGTH];
  static char abs[MAX_LENGTH];
  static char * abs_p = abs;
  static int sign;
  if ( n < 0 )
  {
    *d = ('-');
    n = -n;
  }

  while (lldiv(n,10).quot != 0)
  {
    *abs_p++ = (lldiv(n,10).rem+'0');

    n = (lldiv(n,10).quot);

  } 

    *abs_p++ = (lldiv(n,10).rem+'0'); /* first digit after pos or neg sign must be included */

  reverse(abs); /* contents of abs are originally in reverse order of input */
  strcat(d,abs);

  return &d[0];
}

double nround(double input, double power)
{
	
	double marge = pow(10,power);

	double up = input * marge;

	double result = ((double)(llround(up)))/marge;

	return result;

}

// ftoa rounds accurately up to 15 digits, guranteed

// ftoa can only deal with integral values with an absolute value less than or equal to LLONG_MAX

/* ftoa only works until 9.9999999999999999e15 rounded to

zero decimal places

*/
void ftoa(const double input, const double power) // pow is the '*' in "%.*f"
{
  
  const double in = nround(input,power); 

  static char a[MAX_LENGTH] = "\0";

  int j = 0;

  while (j < strlen(a) ) a[j++] = '\0';

  long long int f_to_i = (long long int)(in); 
  
  strcat(a,lltoa(f_to_i)); strcat(a,".");

  double integral = 0;

  double fraction = 0;

 (in >= 0) ? (fraction = modf(in,&integral)): (fraction = modf(-in,&integral)); /* stores fractional part of input */

  char non_zero_mantissa[1000] = "\0"; /* stores non-zero digits in mantissa after leading zeros following decimal point */

  strcat(non_zero_mantissa,lltoa(llround(fraction*pow(10,power))));


  int i = strlen(non_zero_mantissa);

  while ( i++ < power )
  {
	strcat(a,"0");

  }

  strcat(a,non_zero_mantissa);

#if 0
	return a;
#endif

	int c = 0;

	while ( a[c] != '\0') putchar(a[c++]);
}

//#if 0
int myprintf(char const * s,...)
{

  va_list var_arg;

  char * s_p = (char *)(s-1);

  va_start(var_arg,s);

  while (*++s_p != '\0')
  {
	switch(*s_p)
	{
		case '%':
			switch(*++s_p)
			{
				
				case 'f':
					ftoa(va_arg(var_arg,double),6);
					break;
				case 'd':	
					char const * d = lltoa(va_arg(var_arg,double));
					break;
				case 's':

				case 'c':

			}
			break;
		default:
	  		putchar(*s++);
			break;

	}


  }
  return 1;
}

//#endif

//#if 0
int main(void) 
{

//#if 0
	ftoa(-3.9999,3);
	putchar('\n');
	ftoa(-1.5555,2);
	putchar('\n');
	ftoa(-3.39823929,5);
	putchar('\n');
	ftoa(-3.0000000000000099,15);
	putchar('\n');
	ftoa(-3.6666666666666666,15);
	putchar('\n');
	ftoa(-3.4545,3);
	putchar('\n');
	ftoa(-3.454599,5);
	putchar('\n');
	ftoa(-1.0000000000000009,15);
	putchar('\n');

	ftoa(3.9999,3);
	putchar('\n');
	ftoa(1.5555,2);
	putchar('\n');
	ftoa(3.39823929,5);
	putchar('\n');
	ftoa(3.0000000000000099,15);
	putchar('\n');
	ftoa(3.6666666666666666,15);
	putchar('\n');
	ftoa(3.4545,3);
	putchar('\n');
	ftoa(3.454599,5);
	putchar('\n');
	ftoa(1.0000000000000009,15);
	putchar('\n');

	ftoa(9.9999999999999999e15,14); //FAILS!!!
	putchar('\n');
//#endif


}
//#endif
