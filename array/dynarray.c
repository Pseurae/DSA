#include "array.h"

#define DEFAULT_ARRAY_SIZE 20

void array_grow_if(void **arr, unsigned int eSize)
{
	if (*arr == NULL)
	{
		*arr = malloc(eSize * DEFAULT_ARRAY_SIZE + sizeof(__array_header_t)) + sizeof(__array_header_t);
		__get_ah(*arr)->size = 0;
		__get_ah(*arr)->capacity = DEFAULT_ARRAY_SIZE;
	}
	else if (__get_ah(*arr)->size + 1 >= __get_ah(*arr)->capacity)
	{
		__get_ah(*arr)->capacity *= 2;
		*arr = realloc(__get_ah(*arr), __get_ah(*arr)->capacity + sizeof(__array_header_t)) + sizeof(__array_header_t);
	}
}
