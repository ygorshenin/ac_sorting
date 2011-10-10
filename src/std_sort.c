#include <stdlib.h>

#include "std_sort.h"


static int cmp(const void *_lhs, const void *_rhs) {
  int lhs = * (const int *) _lhs;
  int rhs = * (const int *) _rhs;

  if (lhs < rhs)
    return -1;
  else if (lhs == rhs)
    return 0;
  else
    return +1;
}

void std_qsort(size_t n, int *array) {
  qsort(array, n, sizeof(*array), &cmp);
}
