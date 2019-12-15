#include <stdio.h>
#include <string.h>
#include <limits.h>
int main(void) {

	char s[1024];
	
	int * d = (int*)calloc(INT_MAX,sizeof(int));
	
	d[0] = 1;
	
	d[1] = 2;
	
	for ( int i = 0; (i < INT_MAX) && (d[i] >0);i++) {
		
		printf("%d\n",d[i]);	

	}

	free(d);
	return 0;
}
