#include <stdio.h>
#include <stdlib.h>

int * next_greater_element(int*nums1,int nums1Size,int*nums2,int nums2Size) {
	
	int foundNum = 0;

	int * returnArr = (int*)calloc(nums1Size,sizeof(int));
	
	memset(returnArr,~0x0,sizeof(int)*nums1Size);

	for ( int i = 0; i < nums1Size; i++ ) {
		
		for ( int j = 0; j < nums2Size; j++ ) {
			
			if ( (foundNum == 0) && (nums2[j] != nums1[i])) {
				
				continue;
			}

			else if (nums2[j] == nums1[i]) {
				
				foundNum = 1;

				printf("Found num %d at index: %d\n",nums1[i],j);
			}

			else if ( (foundNum==1) && (nums2[j] > nums1[i]) ) {
				
				returnArr[i] = nums2[j];
				
				break;
			}
		}

		foundNum = 0;
	}

	return returnArr;

}

int main(void) {
	
	int arr1[] = {6,1,5,8};

	int arr2[] = {1,2,3,4,5,6,7,8,9,10};

	int * ans = next_greater_element(arr1,4,arr2,10);

	for ( int i = 0; i < 4; i++ ) {
		printf("%d ",ans[i]);
	}

}
