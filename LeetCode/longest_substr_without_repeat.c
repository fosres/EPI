#include <stdio.h>
#include <stdlib.h>

char * substr(char * src, int start, int end) {
	
	char * ans = (char*)calloc(end-start+1,sizeof(char));

	for ( int i = start; i < end; i++ ) {

		ans[i - start] = src[i];	
		
	}

	return ans;

}

int length_of_longest_substr(char*s) {
	
	if ( strlen(s) == 0 ) { return 0;}
	char * sub = 0; int max = 1;

	for ( int i = 0; i < strlen(s); i++ ) {
		
		for ( int j = i + 2; j <= strlen(s); j++ ) {
			
			sub = substr(s,i,j);

			if ( strchr(sub,sub[strlen(sub)-1]) < &sub[strlen(sub)-1]
			   ) {
				break;
			}

			else {
				max = (strlen(sub) > max ) ? strlen(sub) : max;

			}

			free(sub);
		}

	}

	return max;
}

int main(int argc,char**argv) {

	FILE * in = 0;

	if ( (in = fopen(argv[1],"rb+")) == 0 ) {
		
		fprintf(stderr,"Failed to read file %s\n",argv[1]);

		exit(1);
	}

	size_t file_size = 0;
	
	if ( (fseek(in,0,SEEK_END)) != 0 ) {
		
		fprintf(stderr,"Failed to use fseek\n");	

		exit(1);
	}

	file_size = ftell(in);
	
	printf("File size: %llu\n",file_size);

	rewind(in);
	
	char * s = (char*)calloc(file_size,sizeof(char));
	
	fread(s,sizeof(char),file_size,in);

	printf("%s\n",s);

	printf("%llu\n",length_of_longest_substr(s));
	
	free(s);
}
