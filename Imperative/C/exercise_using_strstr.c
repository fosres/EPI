#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {

  char a[1000] = "Three";
  char * a_zero = a;
  char b[1000] = "ree";
  char * s = strstr(a,b);
  printf("%d\n",(int)(s-a_zero));

}
