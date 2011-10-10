#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#include "merge_sort.h"


static void merge(size_t n, const int *a,
		  size_t m, const int *b,
		  int *c) {
  size_t i = 0, j = 0, k = 0;

  while (i < n && j < m) {
    if (a[i] < b[j])
      c[k++] = a[i++];
    else
      c[k++] = b[j++];
  }

  while (i < n)
    c[k++] = a[i++];

  while (j < m)
    c[k++] = b[j++];
}

void merge_sort(size_t n, int *array) {
  size_t left_size, right_size;
  int *left_part, *right_part;

  if (n < 2)
    return;

  left_size = n / 2;
  left_part = (int*) malloc(left_size * sizeof(*left_part));
  if (left_part == NULL) {
    fprintf(stderr, "Can't allocate memory\n");
    exit(1);
  }

  right_size = n - left_size;
  right_part = (int*) malloc(right_size * sizeof(*right_part));
  if (right_part == NULL) {
    fprintf(stderr, "Can't allocate memory\n");
    exit(1);
  }

  memmove(left_part, array, left_size * sizeof(*left_part));
  memmove(right_part, array + left_size, right_size * sizeof(*right_part));
  merge_sort(left_size, left_part);
  merge_sort(right_size, right_part);
  merge(left_size, left_part, right_size, right_part, array);

  free(left_part);
  free(right_part);
}
