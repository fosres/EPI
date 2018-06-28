#include <stdio.h>
#include <string.h>



void written_amount(unsigned int amount, char * buffer)
{

	
	static char const * ones[] = {"ZERO","ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE","TEN","ELEVEN","TWELVE","THIRTEEN","FOURTEEN","FIFTEEN","SIXTEEN","SEVENTEEN","EIGHTEEN","NINETEEN"};

	static char const * tens[] = {NULL, NULL, "TWENTY","THIRTY","FORTY","FIFTY","SIXTY","SEVENTY","EIGHTY","NINETY"};

	if ( amount == 0)
	{
		strcat(buffer,ones[0]); return;
	}

	if ( amount >= 1000 )
	{
		
		written_amount(amount/1000,buffer);

		strcat(buffer," THOUSAND "); 

		amount %= 1000;

	}

	if ( amount >= 100 )
	{
		
		written_amount(amount/100,buffer);

		strcat(buffer," HUNDRED ");

		amount %= 100;

	}

	if ( amount >= 20 )
	{
		
		strcat(buffer,tens[amount/10]); strcat(buffer," ");

		amount %= 10;

	}

	if (amount == 0 )
	{		
		return;
	}

	strcat(buffer,ones[amount]);


}


int main()
{

	static char s[1000];
#if 0
	written_amount(345,s);
	printf("%s\n",s);
	written_amount(0,s);
	printf("%s\n",s);
	written_amount(1,s);
	printf("%s\n",s);
	written_amount(2,s);
	printf("%s\n",s);
	written_amount(3,s);
	printf("%s\n",s);
	written_amount(4,s);
	printf("%s\n",s);
	written_amount(5,s);
	printf("%s\n",s);
	written_amount(6,s);
	printf("%s\n",s);
	written_amount(7,s);
	printf("%s\n",s);
	written_amount(8,s);
	printf("%s\n",s);
	written_amount(9,s);
	printf("%s\n",s);
	written_amount(10,s);
	printf("%s\n",s);

	written_amount(100,s);
	printf("%s\n",s);
	written_amount(1000,s); 
	printf("%s\n",s);
	written_amount(10000,s); 
	printf("%s\n",s);
	written_amount(67542,s); 
	printf("%s\n",s);
#endif
	written_amount(59999,s); 
	printf("%s\n",s);

}

