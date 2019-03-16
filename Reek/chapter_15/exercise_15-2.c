#include <stdio.h>
#include <string.h>

int main(void)
{
    
    char ch = 0;
    
    int len = 0;

    char buf[81];

    while ( strchr(buf,EOF) == NULL)
    {
//           puts(buf);

           printf("%s\n",gets(buf));

    }

return 0;

}
