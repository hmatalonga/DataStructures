#include "dataio.h"

int main(int argc, char const *argv[]) {
    sl_node *xs = NULL;

    xs = slInsert(xs, 4);
    xs = slInsert(xs, 7);
    xs = slInsert(xs, 2);
    xs = slInsert(xs, 9);
    xs = slInsert(xs, 2);

    slPrint(xs);

    return 0;
}
