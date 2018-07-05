/*
Definitions for a less error-prone memory allocator.
*/
#include <stdlib.h>

#define malloc

#define MALLOC(num,type) (type* )alloc( (num) * sizeof(type) )

extern void *alloc(size_t size);
