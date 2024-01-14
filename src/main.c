#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void push(int);
int pop();
void dump();

void destroy();

Node* head = NULL;

int main(void) {
    push(5);
    push(13);
    push(10);

    dump();

    pop();

    dump();

    destroy();

    return 0;
}

void push(int value) {
    Node* n = malloc(sizeof(Node));

    if (!n) {
        fprintf(stderr, "Failed to allocate for node with value %d", value);
        return;
    }

    n->data = value;
    n->next = head;

    head = n;
}

int pop() {
    int data = head->data;
    Node* next = head->next;

    free(head);

    head = next;

    return data;
}

void dump() {
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

void destroy() {
    while (head != NULL) {
        pop();
    }
}
