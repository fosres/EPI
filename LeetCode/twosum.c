

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int * returnArr = (int*)calloc(2,sizeof(int));
    
    
    for (int i = 0; i < numsSize; i++) {
        
        for (int j = 0; j < numsSize; j++) {
            if (j==i) {continue;}
            
            else if ( (target - nums[i] - nums[j] ) == 0 ) {
                returnArr[0] = i;
                
                returnArr[1] = j;
                
                goto return_statement;
            }
        }
    }
    
    return_statement:
    return returnArr;
}

int main(int argc,char**argv) {
	
	int * arr = (int*)calloc(argc-1,sizeof(int));

	for ( int i = 0; i < argc-1; i++ ) {
		
		arr[i] = (int)strtol(argv[i+1],0,10);
	}

	printf("\n");

	for ( int i = 0; i < (argc-1); i++ ) {
		
		printf("%d ",arr[i]);
	}

	printf("\n");

	int * result = twoSum(arr,argc,22,0);

	for (int i = 0; i < 2 ; i++ ) {
		
		printf("%d ",result[i]);
	}

}


