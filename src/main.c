#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void print_list();

Node* head = NULL;

int main(void) {
    Node* a = malloc(sizeof(Node));
    Node* b = malloc(sizeof(Node));
    Node* c = malloc(sizeof(Node));

    if (!a || !b || !c) {
        fprintf(stderr, "Failed to allocate for one or more nodes\n");
        return -1;
    }

    a->data = 10;
    b->data = 13;
    c->data = 5;

    a->next = b;
    b->next = c;
    c->next = NULL;

    head = a;

    print_list();

    return 0;
}

void print_list() {
    Node* current = head;

    printf("Linked List: ");

    while (current != NULL) {
        printf("%d", current->data);

        if (current->next != NULL) {
            printf(" --> ");
        }

        current = current->next;
    }

    printf("\n");
}
