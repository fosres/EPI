#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

const int BUFFER_SIZE = 100;

double avg_line_ints(char * s)
{
  int IN_WORD = 0;

  int num_words = 0;

  static char buf[11];

  static char * buf_p = &buf[0];

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

    else
    {
        IN_WORD = 0;

       sum += strtol(buf,NULL,10);

       *buf_p = '\0';

       buf_p = &buf[0];
    }

    s++;
  }

return sum/num_words;

}

void line_proc(FILE * input)
{

    char buffer[BUFFER_SIZE];
    
    int num = 0;

    int i = 0;

    printf("\n");

    while (fgets(buffer,BUFFER_SIZE,input) != NULL )
    {
        printf("%5.2f: %s\n\n",avg_line_ints(buffer),buffer);
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
   int exit_status = EXIT_FAILURE; 
    
    FILE * fp = fopen(argv[1],"r+");

    if (fp == NULL)
    {
        perror(argv[1]);

        exit_status = EXIT_FAILURE;
    }
    
    line_proc(fp); 

    if (fclose(fp) != 0)
    {
        perror("fclose");

        exit(EXIT_FAILURE);

    }

return exit_status;
}
