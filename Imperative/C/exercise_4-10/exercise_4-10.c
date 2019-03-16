//exercise_4-10.c
#include <stdio.h>
#include <stdlib.h>

int random_int(int a, int b) // returns random int in range [a,b]
{
	
  double ans;
  double random_frac = (rand()/(double)RAND_MAX); //both rand() and RAND_MAX are ints. So (double)RAND_MAX
  ans = a+random_frac*(b-a)+0.5;
  return (int)ans;
}

int main()
{
   
  int a = 1;
  int b = 100;
  double num;
  for (int i = 0; i < 10000; i++)
  {
  
    printf("%d\n",random_int(a,b));
  }

}
