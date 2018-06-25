#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <float.h>

#define MAX_LENGTH 1000

int doubles_are_equal(double a, double b)
{
  return fabs(a-b) < 1e-15;
}

void reverse (char *s)
{
	for ( int i = 0, j = strlen(s)-1; i < j; i++, j--)
	{
		char temp = s[i];
		s[i] = s[j];
		s[j] = temp;

	}
}

char * ltoa(long long int n)
{
  	static char s[MAX_LENGTH];

	long long int i, sign;

	if ((sign = n) < 0) /* record sign */
		n = -n;	    /* make n positive */
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

char * ftoa(const double input)
{
  double in = input; long long int f_to_i;

  static char a[MAX_LENGTH];

  f_to_i = (long long int)in; 
  
  strcat(a,ltoa(f_to_i)); strcat(a,".");

  double * integral;

  const double fraction = modf(input,integral); /* stores fractional part of input */
  
  static int i; double divisor = 0.1;

  while ( i < 6 ) 	/* by default %f in printf is six decimal digits precise  */
  {
	strcat(a,ltoa(((long long int)(fraction/divisor))%10));

	divisor /= 10; i++;
  }

  return a;
}


int myprintf(char const * s)
{
  while (*s != '\0')
    putchar(*s++);
  return 1;
}

int main(void) 
{
	printf("%d\n",doubles_are_equal(3.999999,4.000000));
	printf("%d\n",doubles_are_equal(0.000000,0.000001));
	printf("%d\n",doubles_are_equal(3.234567,3.234566));
	printf("%d\n",doubles_are_equal(123456.123456,123456.123457));
	printf("%d\n",doubles_are_equal(123456.123456,123456.123457));
	printf("%d\n",doubles_are_equal(123456789.123456,123456789.123457));
	printf("%d\n",doubles_are_equal(9999999999.999998,9999999999.999999)); //FAILS!!!
	printf("%d\n",doubles_are_equal(FLT_MAX,FLT_MAX-1.0e-6)); 	      //FAILS!!!

	printf("%s\n",ltoa(-23));
	printf("%s\n",ltoa(LLONG_MAX));
	printf("%s\n",ltoa(12345678901234));
	printf("%s\n",ltoa(-1));
	printf("%s\n",ltoa(LLONG_MIN)); //FAILS: prints "-("
	printf("%s\n",ltoa(-123456789));
	printf("%s\n",ltoa(INT_MIN));
	printf("%lld\n",LLONG_MIN); //it works


}

