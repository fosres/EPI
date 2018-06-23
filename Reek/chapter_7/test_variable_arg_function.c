#include <stdio.h>
#include <stdarg.h>

float average(int n_values,...)
{
  va_list var_arg;
  int count;
  float sum = 0;

  //Prepare to access the variable arguments

  va_start(var_arg, n_values);

  //Add the values from the variable argument list.

  for (count = 0; count < n_values; count++)
    sum += va_arg(var_arg,int);

  //Done processing variable arguments.

  va_end(var_arg);

  return sum/n_values;
}

int main()
{
  printf("%f\n",average(5,3,5,3,3,3,6));
}
