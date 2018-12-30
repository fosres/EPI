#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void free_arr(void * arr, int SIZE)
{
    
    const void * arr_end = arr + SIZE;

    void * q = NULL;

    while ( arr < arr_end )
    {
        q = arr+1;

        free(arr);

        arr = q;
        
    }

}

int count_lines(FILE * in)
{
    int linenum = 0;

    static char buf[1024];

    while (fgets(buf,1024,in) != NULL) { linenum++; }

    return linenum;

}

int count_chars(FILE * in)
{
   int numchars = 0; 
    
   while (!feof(in))
   {
        fgetc(in);

        numchars++;

   }
    
    
    return numchars;
}

int print_max_line_len(FILE * in)
{
   int max_line_len = 0;

   static char buf[1024];

   while (fgets(buf,1024,in) != NULL)
   {
        if ( strlen(buf) > max_line_len)
        { max_line_len = strlen(buf);}

   }

   return max_line_len;

}

int count_words(FILE * in)
{
    int num_words = 0;

    int IN_WORD = 0;

    char ch = 0;

    while ( (ch = fgetc(in)) != EOF)
    {
        
        if (!isspace(ch) && !IN_WORD)
        {
            IN_WORD = 1;

            num_words++;
        }

        else if (!isspace(ch) && IN_WORD)
        {
            
        }

        else if (isspace(ch) && IN_WORD)
        {
            IN_WORD = 0;

        }

        else // isspace && !IN_WORD
        {

        }
    }
        
        return num_words;

}

int main(int argc, char ** argv)
{

    const char * flags = "clLw";  
   
   int exit_status = EXIT_SUCCESS;

   char * fname = argv[argc-1];

   FILE * in = fopen(fname,"r+");

   if (in == NULL)
   {
       perror(fname);

       exit_status = EXIT_FAILURE;
   }


   while (*++argv != NULL && **argv == '-')
   {
       while ( (*++*argv) != '\0')
       {
        
        switch(**argv)
        {
            case 'c':
            {  
                
                printf("%s: char count: %d\n",fname,count_chars(in));

                rewind(in);
                
                break;
            }
            
            case 'l':
            {
                
                printf("%s: line count: %d\n",fname,count_lines(in));

                rewind(in);
                
                break;
            }

            case 'L':
            {

                printf("%s: Max line length: %d\n",fname,print_max_line_len(in));

                rewind(in);

                break;
            }

            case 'w':
            {

                printf("%s: word count: %d\n",fname,count_words(in));

                rewind(in);
                
                break;
            }

            default:
            {
                printf("Error: Unrecognized character flag: %c\n",**argv);

                exit(EXIT_FAILURE);
                
            }
        }
    } 
   }

   if (fclose(in) != 0)
   {
        perror("fclose");

        exit(EXIT_FAILURE);
   }

   return exit_status;
}
