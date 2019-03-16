#include <stdio.h>

int main()
{
	
	typedef struct LINKED_LIST
	{
		struct LINKED_LIST * fwd;

		int a;

	} linked_list;

	struct LINKED_LIST head;

	struct LINKED_LIST five;

	struct LINKED_LIST ten;

	struct LINKED_LIST fifteen;

	head.a = 3;	

	head.fwd = &five;	

	five.a = 5;

	ten.a = 10;

	fifteen.a = 15;
	
	five.fwd = &ten;
	
	ten.fwd = &fifteen;

	fifteen.fwd = NULL;

	printf("%d\n",ten.fwd->a);
}
