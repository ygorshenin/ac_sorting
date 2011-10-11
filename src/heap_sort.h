#ifndef HEAP_SORT_H
#define HEAP_SORT_H

#include <stddef.h>


/* Makes heap with the largest element in the head. */
void make_heap(size_t n, int *array);

/* Inserts new value into heap of size n. Assumes, that heap points to
 * buffer that can contain at least n + 1 int. */
void push_heap(size_t n, int *heap, int value);

/* Removes head element from heap to tail. After that, logical size of
   heap decreases by one. */
void pop_heap(size_t n, int *heap);

/* Performs heap sorting. */
void heap_sort(size_t n, int *array);


#endif // #ifndef HEAP_SORT_H
