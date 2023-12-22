#ifndef FRONTEAR_SINGLE_LINKED_LIST
#define FRONTEAR_SINGLE_LINKED_LIST

typedef struct {
    void* head;
} SingleLinkedList;

void push(SingleLinkedList*, int);
int pop(SingleLinkedList*);

void print(SingleLinkedList*);

#endif
