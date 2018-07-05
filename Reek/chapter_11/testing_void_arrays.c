#include <stdio.h>

int main(void) {
  void * s = "The";

  printf("%s\n",(char *)s);
  printf("Hello World\n");
  return 0;
}
