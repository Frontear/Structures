#ifndef FRONTEAR_SINGLE_LINKED_LIST
#define FRONTEAR_SINGLE_LINKED_LIST

typedef struct {
    void* head;
} SLL;

SLL*    make_sll();
void    free_sll();

void    push_sll(SLL*, int);
int     pop_sll(SLL*);

void    print_sll(SLL*);

#endif
