#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
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
char * ftoa(const double input, const double power) // pow is the '*' in "%.*f"
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

	return a;

#if 0
	int c = 0;

	while ( a[c] != '\0') putchar(a[c++]);
#endif
}

//#if 0
int myprintf(char const * s,...)
{

  va_list var_arg;

  char * s_p = (char *)(s-1);

  va_start(var_arg,s);

  int ROUND_TO = 0;

  static char rounding[1000];

  while (*++s_p != '\0')
  {
	switch(*s_p)
	{
		case '%':
			{
			switch(*++s_p)
			{
				
			  FLOAT:case 'f':
					{

					if (ROUND_TO)
					{

						ROUND_TO = 0;
						char const * fr_p = ftoa(va_arg(var_arg,double),atoi(rounding));
						while ( *fr_p != '\0') putchar(*fr_p++);

					}
					else
					{
					char const * f_p = ftoa(va_arg(var_arg,double),6);
					while ( *f_p != '\0') putchar(*f_p++);
					}
					break;
					}
				case 'd':
					{
					char const * d_p = (char *)lltoa(va_arg(var_arg,long long int));
					while ( *d_p != '\0') putchar(*d_p++);
					break;
					}
				case 's':
					{
					char const * string_p = va_arg(var_arg,char *);
					while ( *string_p != '\0') putchar(*string_p++);
					break;
					}
				case 'c':
					{
					putchar((char)va_arg(var_arg,int));
					break;
					}
				case '.':
					{
						if (isdigit(*(s_p+1)))
						{
							ROUND_TO = 1;

							int i = 0;

							while (i < strlen(rounding) ) { rounding[i++] = '\0'; }

							strcat(rounding,lltoa(*++s_p));

							while (isdigit(*++s_p)) { strcat(rounding,lltoa(*s_p)); }
						
							--s_p;

							myprintf("%d\n",atoi(rounding));

							goto FLOAT;

						}
						else
						{
							putchar(*s_p);
						}
					


					}
				default:
					{
					putchar(*s_p);
					break;
					}
			}
			break;
		}
		default:
			{
	  		putchar(*s_p);
			break;
			}

	
  }

}
  va_end(var_arg);
  return 1;

}

//#endif

//#if 0
int main(void) 
{

#if 0
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

myprintf("Thatcher Swag\n%s\n%f\n%c\n%d\n","Swiss Cheese",3.45,'T',3535232523);

double a = 3.14, b = 325.3235, c = 790.866;
myprintf("My bank account amount: %f\n",c);

double light_speed = 3.0e8; 

double planck_mass = 2.17647051*pow(10,-8); 

myprintf("Speed of light: %f\n",light_speed*planck_mass);

printf("Speed of light: %f\n",light_speed*planck_mass); //TESTS PASS

myprintf("%f\n",planck_mass);

printf("%f\n",planck_mass); //TESTS_PASS
#endif
myprintf("%.5f\n",3.45678999);

}
//#endif
