#include <stdio.h>
#include <string.h>

void concat(char * buf, char const * str)
{
  strcat(buf,str);

}
int main(void) {

  char const * one[] = {"ZERO","ONE","TWO","THREE","FOUR"};
  static char s[1000];

  static char t[1000];

  char * s_p = s;

  strcat(s_p,"The");

  printf("%s\n",s);

  strcat(s_p," swag");

  printf("%s\n",s);

  strcat(s_p," monster.");

  printf("%s\n",s);

  s_p = t;

  printf("%s\n",s_p);

  strcat(s_p,"YAY!");

  printf("%s\n",s_p);

  strcat(s_p," Slip!");
  
  printf("%s\n",s_p);

  concat(s_p,s);

  printf("%s\n",t);

  printf("%s\n",one[0]);

  strcat(s_p,one[0]);

  printf("%s\n",t);
}

