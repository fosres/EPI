#include <stdio.h>
#include <stdbool.h>

unsigned int swap_bits(unsigned long long int *input, int i, int j) {

  bool bitstream[64];

  bitstream[0] = 0;

  bool *b_p = bitstream;

  bool bit_at_i = *input >> i;

  bool bit_at_j = *input >> j;

  if (bit_at_i == bit_at_j)       {

    return *input;
  }

  int c = 0;

  while (*input > 0 )            {

    if ( c == i || c == j)    {

      *b_p++ = ~(*input & 1);
    }
    else                      {
      *b_p++ = (*input & 1);
    }
    *input >>=1;
    c++;
  }
    i = 1; int hex_to_pow =1;

    unsigned long long int ans = 0;

    while (bitstream[i] != NULL )   {

      ans = ans + (bitstream[i] * hex_to_pow);
      hex_to_pow <<= 4;

    }

    return ans;

  }

  int main()                {

  	unsigned long long int six = 6;



  }

