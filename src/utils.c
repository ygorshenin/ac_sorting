#include <stddef.h>

#include "utils.h"


void swap(int *buffer, size_t i, size_t j) {
  int tmp = buffer[i];
  buffer[i] = buffer[j];
  buffer[j] = tmp;
}
