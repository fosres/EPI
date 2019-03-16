#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
#if 0
    remove("tmpfile"); 
    
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

    printf("Current fpos is %ld\n",ftell(in));
    
    int i = 0;

    char * insert = "Thumbee is a pie eater who ate dates";

    char const * insert_zero = insert; 

    char const * insert_end = insert + strlen(insert);
    
    char ch = 0;
    
    fprintf(in,"%s",insert);

    
    printf("Current fpos is %ld\n",ftell(in));
    
    fgets(buf,1024,in);

    fgets(buf,1024,in);

    fgets(buf,1024,in);

    fgets(buf,1024,in);


    printf("Current fpos is %ld\n",ftell(in));

    insert = insert_zero;

    printf("%s",insert);
    
    while (insert < insert_end )
    {
        fputc(*insert,in);

        insert++;

    }
    
    fprintf(in,"%s","\0");


    if (fclose(in) != 0)
    {
        perror("fclose");

        exit(EXIT_FAILURE);
    }

    printf("%llu\n",FILENAME_MAX);
#endif

    FILE * test = fopen("test.txt","r+");

    rewind(test);

    static char buf[1024];

    while (fgets(buf,1024,test) != NULL)
    {
        printf("%s",buf);
    }



    if (fclose(test) != 0)
    {
        perror("fclose");

        exit(EXIT_FAILURE);

    }

return 0;


}
