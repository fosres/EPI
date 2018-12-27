#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char * sum_beg_ints(char * arr)
{
    char * nl = NULL;

    int sum = 0;

    static char num[11];

    static char * num_p = &num[0];

    int beg_int = 0;

    const char * arr_end = arr + strlen(arr);

    if ( isdigit(*arr))
    {
       while (isdigit(*arr) )
       {
           *num_p++ = *arr++;  
       }

       *num_p = '\0';
        
        sum += strtol(num,NULL,10);   
        
        num_p = &num[0];
    }

    while ( ( (nl = strchr(arr,'\n') ) != NULL ) && (arr < arr_end) )
    {
        if ( isdigit(*(++nl)) )
        {

            while (isdigit(*nl) )
            {
                *num_p++ = *nl++;  
            }

            *num_p = '\0';
        
        sum += strtol(num,NULL,10);   
        
        num_p = &num[0];
       }

        arr = nl;
    }
    
    static char ans[128];

    sprintf(ans,"\n//\tThe sum of the digits at the beginning of the lines is %d\n",sum);

    return &ans[0];
}

void free_arr(void * arr, int size)
{
    void * q = NULL;

    void * temp = NULL;
    
    int i = 0;

    const void * arr_zero = arr;

    while (arr < (arr_zero+size) )
    {
        q = arr+1;

        free(arr); 

        arr = q;
    }

}

int main(int argc, char ** argv)
{ 
    
   int exit_status = EXIT_SUCCESS;
    
    int SIZE = 1024*10000;
    
    char * arr = malloc(sizeof(char)*SIZE);

    FILE * fp = fopen(*(argv+1),"rb");

    if ( fp == NULL )
    {
        perror(argv[1]);

        exit_status = EXIT_FAILURE;

    }
    
    fread(arr,sizeof(arr[0]),SIZE,fp);

    if ( fclose(fp) != 0 )
    {
        perror("fclose");

        exit(EXIT_FAILURE);

    }

    fp = fopen(argv[2],"w+");
    
    fprintf(fp,"%s",arr);
    
    if ( fclose(fp) != 0 )
    {
        perror("fclose");

        exit(EXIT_FAILURE);

    }
    
    fp = fopen(argv[2],"a+");

    fprintf(fp,"%s",sum_beg_ints(arr));

    if ( fclose(fp) != 0 )
    {
        perror("fclose");

        exit(EXIT_FAILURE);

    }

free_arr(arr,SIZE);

return exit_status;

}
