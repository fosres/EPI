//exercise_4-4.c 
#include <stdio.h>

int weight(unsigned int x)
{

	int w = 0;

	while (x != 0)
	{
		x &= (x-1);
		w++;

	}

	return w;


}

int closest_int(unsigned int y)
{

	const int w_y = weight(y);

	unsigned int less_than_y = y - 1;

	unsigned int greater_than_y = y + 1;

	while(1)
	{

		// must return a nonnegative integer

		if (weight(less_than_y) == w_y && less_than_y > 0)
		{

			return less_than_y;

		}
		else
		{
			
			less_than_y--;
		}

		if(weight(greater_than_y) == w_y)
		{
			return greater_than_y;
		}
		else
		{
			greater_than_y++;
		}

	}

}

int isSameWeight(int a, int b)
{

	return weight(a) == weight(b);

}

int main()
{

	printf("%d\n",weight(closest_int(5))==weight(5));
	printf("%d\n",weight(closest_int(5)));
#if 0	

	for ( int i = 1; i < 10001 ; i++)
	{
	printf("%d\n",weight(closest_int(i))==weight(i));	
	}
#endif

}





	




