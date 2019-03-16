#include <stdio.h>
#include <string.h>

int main()
{

typedef struct SALES
{
	char name[20];

	char address[40];

	char model[20];

} sales;

static sales a;

strcat(a.name,"Linus");

printf("%s\n",a.name);

a.name[0] = '\0';

strcat(a.name,"Torvalds");

printf("%s\n",a.name);
}
