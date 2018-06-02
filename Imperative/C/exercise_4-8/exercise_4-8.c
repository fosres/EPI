#include <stdio.h>
#include <string.h>

char * reverseDigits(int x)
{
  char * ans;

  char * s;

  char * r;

  sprintf(s,"%s",x);
  
  *r = *(s + strlen(s) - 1);

  if (x>=0)
  {
    while (r>=s)
      *ans++=*r--;
  }

  else // x < 0
  {
    *ans = *(s+0);
    ans++;

    while(r>s)
    {
      *ans++ = *r--;
    }
  }

  return ans;

}




int main () {
   printf("%s\n",reverseDigits(-312));;

}
