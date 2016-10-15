#include "../dataio.h"

/*
 * Local unit tests
 */
int expect_to(sl_node *elem, int expression);
int expect_value(int parameter, int size);

int main(int argc, char const *argv[]) {
  const int tests = 4;

  sl_node *xs = NULL;
  int checks = 0;

  checks += expect_value(slSize(xs), 0);

  xs = slInsert(xs, 4);
  xs = slInsert(xs, 7);
  xs = slInsert(xs, 2);
  xs = slInsert(xs, 9);
  xs = slInsert(xs, 2);

  checks += expect_value(slIndexOf(xs, 9), 1);
  checks += expect_to(slFirst(xs), 2);
  checks += expect_value(slSize(xs), 5);

  printf("Tests passed [%d/%d]\n", checks, tests);

  slPrint(xs);

  return 0;
}

int expect_to(sl_node *elem, int expression) {
  if (elem == NULL) {
    printf("#Failed: elem is NULL\n");
    return 0;
  }

  if (elem->id == expression)
    return 1;

  printf("#Failed: %d != %d\n", elem->id, expression);

  return 0;
}

int expect_value(int parameter, int size) {
  if (parameter == size)
    return 1;

  printf("#Failed: %d != %d\n", parameter, size);

  return 0;
}
