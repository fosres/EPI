#include <stdio.h>
#include <stdbool.h>

unsigned long long int swap(unsigned long long int x, unsigned i, unsigned j) {

	bool bit_at_i = (x >> i) & 1;

	bool bit_at_j = (x >> j) & 1;

	if ( bit_at_i == bit_at_j)		{

		return x;

	}

	else if ( bit_at_i == 1 && bit_at_j == 0) {

		x &= ~(1 << i);

		x |= (1 << j);

	}

	else	/*bit_at_i == 0 && bit_at_j == 1 */ {
		
		x &= ~(1 << j);

		x |= (1 << i);

	}

	
	return x;
}

int main() 						{

	
	unsigned long long int x = ~0;
	
	printf("%llu\n",sizeof(x));
	
	printf("unsigned long long int: %llu\n",swap(057,5,4));
	
	printf("long long octal: %llo\n",swap(057,5,4));
	
	

}

