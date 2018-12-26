#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void sum_beg_ints(char * arr)
{
    char * nl = NULL;

    int sum = 0;

    while ( (nl = strchr(arr,'\n')) != NULL )
    {
        if ( isdigit(*(nl+1)) )
        {sum += *(nl+1);}
    }

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
    
    const int SIZE = 1024*10000;

    char * arr = malloc(sizeof(char)*SIZE);

    FILE * fp = fopen(*(argv+1),"rb");

    if ( fp == NULL )
    {
        perror(argv[1]);

        exit_status = EXIT_FAILURE;

    }

    fread(arr,sizeof(arr[0]),SIZE,fp);

    fclose(fp);

    fp = fopen(argv[2],"wb");

    if ( fp == NULL )
    {
        perror(*(argv+2));

        exit_status = EXIT_FAILURE;

    }

    fwrite(arr,sizeof(arr[0]),SIZE,fp);
    
    if ( fclose(fp) != 0 )
    {
        perror("fclose");

        exit(EXIT_FAILURE);

    }

fclose(fp);

free_arr(arr,SIZE);

return exit_status;
}
