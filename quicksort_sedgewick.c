#include <stdio.h>

int partition(int a[], int l, int r)
{

	int i = l-1; int j = r; int v = a[r];

	while (1)
	{
		do
		{
			i++;
		}while(a[i] < v);

		do
		{
			j--;
		}while(v < a[j] && j != l);

		if ( i >= j) {break;}

		int temp = a[i];

		a[i] = a[j];

		a[j] = temp;

	}

	int temp = a[i];

	a[i] = a[r];

	a[r] = temp;

	return i;

}

void quicksort(int a[], int l, int r)
{
	if (r <= l) {return;}

	int i = partition(a,l,r);

	quicksort(a,l,i-1);

	quicksort(a,i+1,r);
}
int main()
{
	int a[] = {4,3,2,1,0,9,6,5};

	quicksort(a,0,7);

	for ( int i = 0; i < 8; i++)
	{
		printf("%d\n",a[i]);
	}

	return 0;
}
