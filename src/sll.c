#include <stdio.h>
#include <stdlib.h>
#include "sll.h"

typedef struct Node {
    int value;
    struct Node* next;
} Node;

void push(SingleLinkedList* list, int value) {
    // allocate the node
    Node* node = malloc(sizeof(Node));

    // set values explicitly
    node->value = value;
    node->next = NULL;

    if (list->head == NULL) {
        list->head = node;
        return;
    }

    Node* current = list->head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = node;
}

int pop(SingleLinkedList* list) {
    Node* parent = list->head;
    Node* child = parent->next;

    while (child != NULL) {
        if (child->next == NULL) {
            break;
        }

        parent = child;
        child = child->next;
    }

    int value = child->value;

    parent->next = NULL;
    free(child);

    return value;
}

void print(SingleLinkedList* list) {
    Node* current = list->head;

    printf("Contents of single linked list:\n");

    while (current != NULL) {
        printf("%d", current->value);
        // show a visual "joining" chain
        if (current->next != NULL) {
            printf(" -> ");
        }

        // done regardless of whether NULL or not, because loop checks and breaks accordingly
        current = current->next;
    }

    printf("\n");
}
