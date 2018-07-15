#include <stdio.h>

int partition(int a[],int p,int r);
void quicksort(int a[],int p, int r)
{

	int q = 0;

	if ( p < r )
	{ q = partition(a,p,r);}

	quicksort(a,p,q);
	quicksort(a,q+1,r);

}

int partition(int a[],int p, int r)
{
	
	int x = a[p];

	int i = p-1;

	int j = r+1;

	while (1)
	{

		do
		{
			j--;
		}while(a[j] <= x);

		do
		{
			i++;
		}while(a[i]>=x);

		if (i<j)
		{
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
		else
		{ return j;}
	}

}

int main()
{

	int a[] = {4,56,9,2,1,29,10,11,13};
	printf("%lu\n",sizeof(a)/sizeof(int));
	quicksort(a,0,sizeof(a)/sizeof(int)-1);

}


