#include <assert.h>
#include <limits.h>
#include <stddef.h>

#include "heap_sort.h"
#include "utils.h"


static inline size_t left_child(size_t index) {
  return 2 * index + 1;
}

static inline size_t right_child(size_t index) {
  return 2 * index + 2;
}

// Index must be greater than zero.
static inline size_t parent(size_t index) {
  return (index - 1) / 2;
}

static void heapify(size_t n, int *heap, size_t index) {
  int largest = index;
  size_t left = left_child(index);
  size_t right = right_child(index);

  if (left < n && heap[left] > heap[largest])
    largest = left;
  if (right < n && heap[right] > heap[largest])
    largest = right;

  if (largest != index) {
    swap(heap, index, largest);
    heapify(n, heap, largest);
  }
}

static void update(size_t n, int *heap, size_t index, int value) {
  if (value == heap[index])
    ;
  else if (value < heap[index]) {
    heap[index] = value;
    heapify(n, heap, index);
  } else {
    size_t parent_index;

    while (index != 0) {
      parent_index = parent(index);
      if (heap[parent_index] >= value)
	break;

      heap[index] = heap[parent_index];
      index = parent_index;
    }
    heap[index] = value;
  }
}

void make_heap(size_t n, int *array) {
  size_t i;

  for (i = 0; i < n; ++i)
    heapify(n, array, n - i - 1);
}

void push_heap(size_t n, int *heap, int value) {
  heap[n] = INT_MIN;
  update(n + 1, heap, n, value);
}

void pop_heap(size_t n, int *heap) {
  if (n > 1) {
    swap(heap, 0, n - 1);
    heapify(n - 1, heap, 0);
  }
}

void heap_sort(size_t n, int *array) {
  size_t i;

  make_heap(n, array);
  for (i = 0; i < n; ++i)
    pop_heap(n - i, array);
}
