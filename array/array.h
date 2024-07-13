#ifndef GUARD_ARRAY_H
#define GUARD_ARRAY_H

#include <stdlib.h>

typedef struct __array_header_s
{
	unsigned int size, capacity;
} __array_header_t;

#define __get_ah(ARR) \
	((__array_header_t *)((void *)ARR - sizeof(__array_header_t)))

#define array_t(T) T*
#define array_push(ARR, I) \
	(array_grow_if((void *)&ARR, sizeof(*ARR)), ARR[__get_ah(ARR)->size++] = I)

#define array_front(ARR) (ARR[0])
#define array_back(ARR) (ARR[__get_ah(ARR)->size - 1])

#define array_size(ARR) ((ARR == 0) ? 0 : __get_ah(ARR)->size)

#define array_pop(ARR) \
	do { if (ARR != 0 && __get_ah(ARR)->size > 0) __get_ah(ARR)->size--; } while (0)

#define array_free(ARR) \
	do { if (ARR) { free(__get_ah(ARR)); ARR = NULL; } } while (0)

void array_grow_if(void **arr, unsigned int eSize);

#endif // ARRAY_H
