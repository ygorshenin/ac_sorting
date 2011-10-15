#include <assert.h>
#include <limits.h>
#include <stddef.h>
#include <stdlib.h>
#include <strings.h>

#include "radix_sort.h"


static void counting_sort(size_t n, int *array, size_t k, const int *keys) {
  size_t *count = (size_t*) calloc(k, sizeof(*count));
  int *backup = (int*) calloc(n, sizeof(*backup));
  size_t i, j;

  assert(count != NULL);
  assert(backup != NULL);

  memmove(backup, array, n * sizeof(*array));

  for (i = 0; i < n; ++i)
    ++count[keys[i]];

  for (i = 1; i < k; ++i)
    count[i] += count[i - 1];

  for (i = 0, j = n - 1; i < n; ++i, --j)
    array[--count[keys[j]]] = backup[j];

  free(count);
  free(backup);
}

void radix_sort(size_t n, int *array) {
  const size_t k = 1 << CHAR_BIT, mask = (1 << CHAR_BIT) - 1;
  int *keys = (int*) calloc(n, sizeof(*array));
  size_t i, offset;

  assert(keys != NULL);

  for (offset = 0; offset < sizeof(*array); ++offset) {
    const size_t num_bits = CHAR_BIT * offset;
    for (i = 0; i < n; ++i)
      keys[i] = (array[i] >> num_bits) & mask;
    counting_sort(n, array, k, keys);
  }

  free(keys);
}
