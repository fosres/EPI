#include <stdio.h>
#include <stdarg.h>
#include <assert.h>

int array_offset(int arrayinfo[],...)
{

	va_list var_arg;

	va_start(var_arg,arrayinfo);

	int i = 0; int lo_index; int loc = 0;
	
	assert(arrayinfo[0] >= 1 && arrayinfo[0] <= 10);
	
	while (i++ < arrayinfo[0])
	{
		if (loc == 0)
		{
			loc = va_arg(var_arg,int)-(arrayinfo[lo_index=1]);
		}
		else
		{
			lo_index += 2; 
			
			assert((lo_index+1) >= lo_index);

			loc = loc*(arrayinfo[(lo_index+1)] - arrayinfo[lo_index]+1)+va_arg(var_arg,int)-lo_index;
		}
	}




	va_end(var_arg);

	return loc;

}

int main()
{
	
	static int arrayinfo[] = {3,4,6,1,5,-3,3};

	printf("%d\n",array_offset(arrayinfo,4,1,3));

}
