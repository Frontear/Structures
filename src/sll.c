#include <stdio.h>
#include <stdlib.h>
#include "sll.h"

typedef struct Node {
    int value;
    struct Node* next;
} Node;

SLL* make_sll() {
    SLL* list = malloc(sizeof(SLL));

    if (list == NULL) {
        return NULL;
    }

    // set values explicitly to ensure data is consistent (could also use calloc tbh)
    list->head = NULL;

    return list;
}

void free_sll(SLL* list) {
    while (list->head != NULL) {
        pop_sll(list);
    }
}

void push_sll(SLL* list, int value) {
    Node* node = malloc(sizeof(Node));
    if (node == NULL) {
        // TODO: set errno?
        return;
    }

    node->value = value;
    node->next = NULL;

    // for no elements, make this new node the HEAD of our list
    if (list->head == NULL) {
        list->head = node;
        return;
    }

    // recursively traverse down children until we reach the end
    Node* current = list->head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = node;
}

int pop_sll(SLL* list) {
    Node* parent = list->head;

    // nothing to pop
    if (parent == NULL) {
        return -1;
    }

    Node* child = parent->next;

    // one element in list, pop and remove HEAD
    if (child == NULL) {
        int value = parent->value;
        free(parent);
        list->head = NULL;

        return value;
    }

    // recurse down while tracking children
    while (child != NULL) {
        if (child->next == NULL) {
            break;
        }

        parent = child;
        child = child->next;
    }

    // save value, and free up the node, moving back the list
    int value = child->value;
    parent->next = NULL;
    free(child);

    return value;
}

void print_sll(SLL* list) {
    Node* current = list->head;

    printf("Contents of single linked list:\n");

    // no elements in list
    if (current == NULL) {
        printf("EMPTY\n");
        return;
    }

    // recursively travel down and print values out
    while (current != NULL) {
        printf("%d", current->value);
        // show a visual "joining" chain
        if (current->next != NULL) {
            printf(" -> ");
        }

        current = current->next;
    }

    printf("\n");
}
