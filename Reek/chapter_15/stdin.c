#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    FILE * in = NULL;

    if ( ( in = fopen("test_file.txt","w+") ) == NULL)
    {
        perror("test_file.txt");

        exit(EXIT_FAILURE);

    }

    fputs("I like cookies.\nI like cookies.\nI like cookies.\ntI like cookies.\ntI like cookies.\ntI like cookies.\ntI like cookies.\ntI like cookies.\ntI like cookies.\ntI like cookies.\ntI like cookies.\ntI like cookies.\nt",in);

    static char buf[1024];

    long offs = 0;

    rewind(in);

    fseek(in,4,SEEK_SET);

    printf("Current fpos is %ld\n",ftell(in));
    
    int i = 0;

    char * insert = "Thumbee is a pie eater who ate dates";

    char const * insert_zero = insert; 

    char const * insert_end = insert + strlen(insert);
    
    char ch = 0;

    while (insert < insert_end )
    {
        fputc(*insert,in);

        insert++;

    }
    
    printf("Current fpos is %ld\n",ftell(in));
    

    while ( (ch = fgetc(in)) != '\n')
        ;
    
    fgetc(in);

    printf("Current fpos is %ld\n",ftell(in));

    insert = insert_zero;

    printf("%s",insert);
    
    while (insert < insert_end )
    {
        fputc(*insert,in);

        insert++;

    }

    if (fclose(in) != 0)
    {
        perror("fclose");

        exit(EXIT_FAILURE);
    }

    printf("%llu\n",FILENAME_MAX);


}
