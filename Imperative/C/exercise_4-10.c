//exercise_4-10.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double random_frac()
{
	
  double ans;
  ans = (double)rand()/(double)RAND_MAX;
  return ans;
}

int main()
{
   
  int a = 0;
  int b = 1;
  double num;
  for (int i = 0; i < 10000; i++)
  {
    num = a+random_frac()*(b-a)+0.5;
  
    printf("%d\n",(int)num);
  }

  printf("%d\n",RAND_MAX);
}
