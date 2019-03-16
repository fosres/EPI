#include <stdio.h>
#include <string.h>

int main(void) {
  
  typedef struct INFO
  {
    char date[1000];

    char time[1000];

    char called[1000];


  } INFO;

  static INFO a;
  strcat(a.date,"8-27-2018");

  strcat(a.time,"3:47PM");

  printf("%s\n",a.time);
}
