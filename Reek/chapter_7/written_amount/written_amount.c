#include <stdio.h>
#include <string.h>

void ptrstrcat(char * buffer, char const * str)
{

  while ( *buffer != '\0')
    buffer++;

  while (*str != '\0')
    *buffer++ = *str++;


}

void written_amount_compute(unsigned int amount, char str[]);

void written_amount(unsigned int amount, char * buffer)
{

	static char s[1000]; static char * s_p = s; while (*s_p != '\0' ) *s_p++ = '\0';

	written_amount_compute(amount,s);

	buffer = s;

}

void written_amount_compute(unsigned int amount, char str[] )
{

	char const * ones[] = {"ZERO","ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE","TEN","ELEVEN","TWELVE","THIRTEEN","FOURTEEN","FIFTEEN","SIXTEEN","SEVENTEEN","EIGHTEEN","NINETEEN"};

	char const * tens[] = {NULL, NULL, "TWENTY","THIRTY","FOURTY","FIFTY","SIXTY","SEVENTY","EIGHTY","NINETY"};

	if ( amount == 0)
		strcat(str,ones[0]); return;

	if ( amount >= 1000 )
	{
		
		written_amount_compute(amount/1000,str);

		strcat(str," THOUSAND "); 

		amount %= 1000;

	}

	if ( amount >= 100 )
	{
		
		written_amount_compute(amount/100,str);

		strcat(str," HUNDRED ");

		amount %= 100;

	}

	if ( amount >= 20 )
	{
		
		strcat(str,tens[amount/10]); strcat(str," ");

		amount %= 10;

	}

	if (amount == 0 )
		return;

	strcat(str,ones[amount]);

}

int main()
{

	static char s[1000];

	written_amount_compute(62347,s);

	printf("%s\n",s);

}
