#include <stdio.h>
#include "sll.h"

int main(void) {
    SingleLinkedList list;

    push(&list, 4);
    push(&list, 8);
    push(&list, 9);

    print(&list);

    printf("Removed: %d\n", pop(&list));

    print(&list);

    return 0;
}
