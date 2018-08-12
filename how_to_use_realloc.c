#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int * a = (int *)malloc(3*sizeof(int));

  a[0] = 1;

  a[1] = 2;

  a[2] = 9;

  int *a_mod = (int *)realloc(a,4*sizeof(int));

  a[3] = 5;

  int * i = &a[0];

  while (i < &a[4]) {printf("%d\n",*i++);}

  return 0;
}
