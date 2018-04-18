#include <stdio.h>

int main() {

	for ( int n = 5; n > 0; n-- ) {

		for ( int c = 0; c < n; c++ ) {

			printf("%c",'#');


		}	

		printf("%c",'\n');
	
	}

}
