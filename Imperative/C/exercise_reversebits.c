//exercise_reversebits.c

#include <stdio.h>

unsigned long long int reversebits(unsigned long long int input)
{

  int s = 63;

  while (((input >> s)&1)==0) {s--;}

  int i = s; unsigned long long int ans = 0;

  while (input != 0)
  {
    ans|=((input&1) << i);

    input >>= 1;

    i--;


  }

  return ans;



}

int main(void) {
  printf("%llu\n",reversebits(13));
  return 0;
}
