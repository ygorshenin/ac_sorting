#include <stdbool.h>
#include <stdlib.h>

#include "quick_sort.h"
#include "utils.h"


static void partition(size_t n, int *array, bool randomized,
		      size_t *left, size_t *right) {
  size_t i;
  int pivot;

  if (randomized)
    swap(array, rand() % n, n - 1);
  pivot = array[n - 1];

  *left = 0;
  for (i = 0; i < n; ++i)
    if (array[i] < pivot) {
      swap(array, *left, i);
      ++*left;
    }

  *right = *left;
  for (i = *left; i < n; ++i)
    if (array[i] == pivot) {
      swap(array, *right, i);
      ++*right;
    }
}

void quick_sort(size_t n, int *array) {
  if (n >= 2) {
    size_t left, right;
    partition(n, array, false, &left, &right);
    quick_sort(left, array);
    quick_sort(n - right, array + right);
  }
}

void randomized_quick_sort(size_t n, int *array) {
  if (n >= 2) {
    size_t left, right;
    partition(n, array, true, &left, &right);
    randomized_quick_sort(left, array);
    randomized_quick_sort(n - right, array + right);
  }
}
