#include <stdio.h>

int partition(int a[], int p, int r);
void quicksort(int a[], int p, int r)
{
	if (p < r)
	{ 
		int q = partition(a,p,r);

		quicksort(a,p,q);

		quicksort(a,q+1,r);

	}
}

int partition(int a[], int p, int r)
{
	int x = a[p];

	int i = p - 1;

	int j = r + 1;

	while (1)
	{
		while (a[--j] <= x);

		while (a[++i] >= x);

		if (i < j)
		{ 
			int temp = a[i];

			a[i] = a[j];

			a[j] = temp;

		}
		else
		{ break;}
	}
	return j;
}

int main()
{
	int a[] = {4,3,2,1};

	quicksort(a,0,3);

	for ( int i = 0; i < 4; i++)
	{ printf("%d\n",a[i]); }
}
