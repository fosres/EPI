#include <stdio.h>
#include "quicksort.h"

void swap(ELEMENT_TYPE * a, ELEMENT_TYPE * b)
{
	ELEMENT_TYPE temp = *a;

	*a = *b;

	*b = temp;
}

void quicksort(ELEMENT_TYPE a[],ELEMENT_TYPE l, ELEMENT_TYPE r)
{
	
	ELEMENT_TYPE i;

	if ( l >= r ) return;

	i = partition(a,l,r);

	quicksort(a,l,i-1);
	
	quicksort(a,i+1,r);

}

ELEMENT_TYPE partition(ELEMENT_TYPE a[], ELEMENT_TYPE l, ELEMENT_TYPE r)
{

	ELEMENT_TYPE i = l-1; ELEMENT_TYPE j = r;

	ELEMENT_TYPE v = j;

	while (1)
	{
		while (a[++i] <= v)
			;

		while (v <= a[--j])
		{
			if ( j == l) break;
		}

		if (i >= j)
		{
			break;
		}

		swap(&a[i],&a[j]);
	}

	swap(&a[i],&a[r]);

	return i;
}

