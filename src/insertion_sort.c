#include "insertion_sort.h"


void insertion_sort(size_t n, int *array) {
  size_t i, j;
  int t;

  if (n < 2)
    return;

  for (i = 1; i < n; ++i) {
    j = i;
    t = array[i];

    while (j > 0 && array[j - 1] > t) {
      array[j] = array[j - 1];
      --j;
    }
    array[j] = t;
  }
}
