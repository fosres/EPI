#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>
#include <time.h>

const int BUFFER_SIZE = 1024;


int gen_int_file(char * fname) 
{
    srand((unsigned)time(NULL));

    int exit_status = 0; 
    
    FILE * fp = fopen(fname,"w+");
    
    if ( fp == NULL)
    {
        perror(fname);
        
        exit_status = EXIT_FAILURE;

    }
    
    int line_word_size = 0;

    int i = 0;

    int j = 0;

    while ( i < 2000 )
    {
        line_word_size = (int)((double)rand()/RAND_MAX*100.+0.5);  
        
        while ( j < line_word_size )
        {
            fprintf(fp,"%d ",(int)((double)rand()/RAND_MAX*1000.+0.5)); 

            j++;
        }

            fprintf(fp,"\n"); 

            j = 0;

        i++;
    }
    
    if (fclose(fp) != 0)
    {
        perror("fclose");

        exit(EXIT_FAILURE);

    }
    
    return exit_status;
}


double avg_line_ints(char * s)
{
  int IN_WORD = 0;

  int num_words = 0;

  char buf[64];

  char * buf_p = &buf[0];

  double sum = 0;
  
  while ( *s != '\0')
  {
    if (isalnum(*s) && !IN_WORD)
    {
        IN_WORD = 1; 

        num_words++;

        *buf_p++ = *s;
    }

    else if (isalnum(*s) && IN_WORD)
    { 
    
        *buf_p++ = *s;
    
    }

    else if (!isalnum(*s) && IN_WORD)
    {
        IN_WORD = 0;

       sum += strtol(buf,NULL,10);

       *buf_p = '\0';

       buf_p = &buf[0];
    }

    else{}

    s++;
  }

return sum/num_words;

}

void line_proc(FILE * input, FILE * output)
{

    char buffer[BUFFER_SIZE];
    
    int num = 0;

    int i = 0;

    while (fgets(buffer,BUFFER_SIZE,input) != NULL )
    {
        fprintf(output,"%5.2f: %s\n\n",avg_line_ints(buffer),buffer);
    }

}

void free_arr(void * arr,int SIZE)
{
    void * q = NULL;

    const void * arr_end = arr+SIZE;

    while (arr < arr_end)
    {
        q = arr+1;

        free(arr);

        arr = q;
    }

}

int main(int argc, char ** argv)
{
    
    static char fname[64]; 
    
    printf("Enter desired name of file for generated random ints: "); 

    scanf("%s",&fname[0]);
    
    gen_int_file(fname);

    int exit_status = EXIT_FAILURE; 
    
    FILE * fp = fopen(fname,"r+");

    FILE * op = fopen(argv[1],"w+");

    if (fp == NULL)
    {
        perror(fname);

        exit_status = EXIT_FAILURE;
    }

    if (op == NULL)
    {
        perror(argv[1]);

        exit_status = EXIT_FAILURE;
    }
    
    line_proc(fp,op); 

    if (fclose(fp) != 0)
    {
        perror("fclose");

        exit(EXIT_FAILURE);

    }

    if (fclose(op) != 0)
    {
        perror("fclose");

        exit(EXIT_FAILURE);

    }

return exit_status;
}
