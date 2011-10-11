#ifndef HEAP_SORT_H
#define HEAP_SORT_H

#include <stddef.h>

/* Rearranges the elements in the range [0, n) in such a way that they
   form a heap.  Internally, a heap is a tree where each node links to
   values not greater than its own value. In heaps generated by
   make_heap, the specific position of an element in the tree rather
   than being determined by memory-consuming links is determined by
   its absolute position in the sequence, with first element being
   always the highest value in the heap. */
void make_heap(size_t n, int *array);

/* Given a heap range [0, n - 1), this function extends the range
   considered a heap to [0, n) by placing the value in (n - 1) into
   its corresponding location in it. */
void push_heap(size_t n, int *heap);

/* Rearranges the elements in the range [0, n) in such a way that the
   part considered a heap is shortened by one by removing its highest
   element. The function actually moves the value at first to (n - 1),
   and adjusts the values of the elements in the range [0, n - 1) so
   that this part of the range retains the heap property (with its
   first element being the new highest value). */
void pop_heap(size_t n, int *heap);

/* Performs heap sorting algorithm. */
void heap_sort(size_t n, int *array);


#endif // #ifndef HEAP_SORT_H
