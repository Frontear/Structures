#ifndef FRONTEAR_STRUCTS_SLL
#define FRONTEAR_STRUCTS_SLL

void*   sll_create();
void    sll_destroy(void*);

void    sll_push(void*, int);
int     sll_pop(void*);

void    sll_print(void*);

#endif
