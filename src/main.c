#include "lib/sll.h"

int main(void) {
    void* list = sll_create();

    sll_push(list, 5);
    sll_push(list, 13);
    sll_push(list, 15);

    sll_print(list);

    sll_pop(list);

    sll_print(list);

    sll_destroy(list);

    return 0;
}
