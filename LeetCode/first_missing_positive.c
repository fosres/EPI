#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>

int first_missing_positive(int *nums, int numsSize) {

	if ( numsSize == 0) { return 1;}

	bool * hash_table = (bool*)calloc(INT_MAX,sizeof(bool));
	
	int i = 0, j = numsSize-1;


	for ( ; i < j; i++,j-- ) {
		
		if ( nums[i] > 0 ) {
			
			hash_table[nums[i]-1] = 1;
		}

		if ( nums[j] > 0 ) {
			
			hash_table[nums[j]-1] = 1;
		}

	}

	if ( (i==j) && (nums[i] > 0) ) {
		
		hash_table[nums[i]-1] = 1;
	}

	int ans = 1;

	while ( hash_table[ans-1] == 1 ) { ans++;}
	
	free(hash_table);

	return ans;

}

int main(int argc,char**argv) {
	
	int nums[argc-1];

	for ( int i = 0; *++argv != 0; i++)  {

		nums[i] = (int)strtol(*argv,0,10);	
		
	}

	printf("%d\n",first_missing_positive(nums,argc-1));

}
