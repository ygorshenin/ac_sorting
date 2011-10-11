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

static void update(size_t n, int *heap, size_t index) {
  size_t parent_index;

  if (index == 0)
    return;

  parent_index = parent(index);
  if (heap[index] > heap[parent_index]) {
    swap(heap, index, parent_index);
    update(n, heap, parent_index);
  }
}

void make_heap(size_t n, int *array) {
  size_t i;

  for (i = 0; i < n; ++i)
    heapify(n, array, n - i - 1);
}

void push_heap(size_t n, int *heap) {
  update(n, heap, n - 1);
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
