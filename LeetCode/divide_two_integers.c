#include <limits.h>
int divide(int dividend, int divisor) {
	
	int sign = ((dividend <0) ^ (divisor<0)) ? -1 : 1;
	
	dividend = (int)abs(dividend);
	
	dividend = (dividend < 0)?INT_MAX:dividend;

	printf("%d\n",dividend);

	divisor = abs(divisor);
	
	divisor = (divisor < 0)?INT_MAX:divisor;	
	
	printf("%d\n",divisor);

	int output = 0;

	while (dividend >= divisor) {
		
		dividend -= divisor;

		output++;
	}

	return sign * output;

}

int main(int argc,char**argv) {
	
	printf("%d\n",divide((int)strtol(argv[1],0,10),(int)strtol(argv[2],0,10)));

	return 0;
}
