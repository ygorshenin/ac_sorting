#include <stdlib.h>

#include "std_qsort.h"


static int cmp(const void *_lhs, const void *_rhs) {
  int lhs = * (const int *) _lhs;
  int rhs = * (const int *) _rhs;

  return (lhs > rhs) - (lhs < rhs);
}

void std_qsort(size_t n, int *array) {
  qsort(array, n, sizeof(*array), &cmp);
}
