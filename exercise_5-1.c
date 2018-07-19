#include <stdio.h>

void dutch_problem(int a[], const int pivot_i, const int len)
{
	int i = 0; 

	int temp[len]; int j = 0; const int pivot = a[pivot_i];

	while (i < len)
	{
		if (a[i] < pivot)
		{
			temp[j++] = a[i++];
		}
		else
		{ i++;}
	}

	i = 0;

	while (i < len)
	{
		if (a[i] == pivot)
		{ temp[j++] = a[i++];}
		else 
		{i++;}
	}

	i = 0;

	while (i < len)
	{
		if (a[i] > pivot)
		{temp[j++] = a[i++];}
		else
		{i++;}
	}

	i = 0;

	while (i < len)
	{
		a[i] = temp[i];
		i++;
	}

	i = 0;

#if 0
	while ( i < len)
	{ printf("%d\n",a[i++]); }
#endif
}

int main()
{
	
	int a[] = {0,1,2,0,2,1,1};

	dutch_problem(a,3,sizeof(a)/sizeof(int));

}
