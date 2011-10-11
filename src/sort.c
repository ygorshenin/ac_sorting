#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#include "heap_sort.h"
#include "insertion_sort.h"
#include "merge_sort.h"
#include "quick_sort.h"
#include "std_qsort.h"
#include "io.h"


typedef void (*sorting_method) (size_t, int*);


static void display_usage(int argc, char **argv,
			  size_t num_methods,
			  const char * const* names) {
    size_t i;

    fprintf(stderr, "Usage: ./%s [sorting method]\n", argv[0]);
    fprintf(stderr, "where [sorting method] is one of the following:\n");
    for (i = 0; i < num_methods; ++i)
      fprintf(stderr, "  %s\n", names[i]);
    exit(1);
}

sorting_method select_method(size_t num_methods,
			     const char * const * names,
			     sorting_method * methods,
			     const char *name) {
  size_t i = 0;

  for (i = 0; i < num_methods; ++i)
    if (strcmp(name, names[i]) == 0)
      return methods[i];
  return NULL;
}


int main(int argc, char **argv) {
  const char * const sorting_method_names[] = {
    "insertion_sort",
    "merge_sort",
    "quick_sort",
    "randomized_quick_sort",
    "std_qsort",
    "heap_sort",
  };

  sorting_method methods[] = {
    &insertion_sort,
    &merge_sort,
    &quick_sort,
    &randomized_quick_sort,
    &std_qsort,
    &heap_sort,
  };

  const size_t num_methods =
    sizeof(sorting_method_names) / sizeof(*sorting_method_names);

  if (argc != 2)
    display_usage(argc, argv, num_methods, sorting_method_names);

  sorting_method method = select_method(num_methods, sorting_method_names,
					methods, argv[1]);

  if (method == NULL) {
    fprintf(stderr, "Incorrect method name: %s\n", argv[1]);
    exit(1);
  }

  size_t n;
  int *array;

  read_data(&n, &array);
  (*method)(n, array);
  write_data(n, array);

  free(array);
  return 0;
}
