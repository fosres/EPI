//main.c
#ifndef __STDIO_H__
#define __STDIO_H__
#include <stdio.h>

int main()
{
	char c;	
	while ((c = getChar()) != '\n')
	{
		putChar(c);
	}


}

#endif
