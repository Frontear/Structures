#include <stdio.h>
#include "sll.h"

int main(void) {
    SLL* list = make_sll();

    if (list == NULL) {
        printf("Failed to allocate list\n");
        return 1;
    }

    print_sll(list);

    push_sll(list, 3);
    push_sll(list, 6);
    push_sll(list, 9);
    print_sll(list);

    pop_sll(list);
    print_sll(list);

    push_sll(list, 19);
    print_sll(list);

    pop_sll(list);
    pop_sll(list);
    pop_sll(list);
    print_sll(list);

    free_sll(list);

    return 0;
}
