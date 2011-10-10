#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "io.h"


void read_data(size_t *n, int **array) {
  size_t i;
  int *buffer;

  scanf("%zu", n);

  buffer = (int*) malloc(*n * sizeof(*buffer));
  if (buffer == NULL) {
    fprintf(stderr, "Can't allocate memory\n");
    exit(1);
  }

  for (i = 0; i < *n; ++i)
    scanf("%d", &buffer[i]);

  *array = buffer;
}

void write_data(size_t n, const int *array) {
  size_t i;

  for (i = 0; i < n; ++i)
    printf("%d\n", array[i]);
}
