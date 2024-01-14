#include <stdio.h>
#include <stdlib.h>

#include "sll.h"

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct List {
    Node* head;
} List;

void*   sll_create() {
    List* list = malloc(sizeof(List));

    if (!list) {
        fprintf(stderr, "Failed to allocate single linked list.\n");
        return NULL;
    }

    list->head = NULL;

    return list;
}

void    sll_destroy(void* list) {
    while (((List*) list)->head != NULL) {
        sll_pop(list);
    }

    free(list);
}

void    sll_push(void* list, int value) {
    Node* node = malloc(sizeof(Node));

    if (!node) {
        fprintf(stderr, "Failed to push value %d\n", value);
        return;
    }

    node->data = value;
    node->next = ((List*) list)->head;

    ((List*) list)->head = node;
}

int     sll_pop(void* list) {
    Node* head = ((List*) list)->head;

    int data = head->data;
    Node* next = head->next;

    free(head);

    ((List*) list)->head = next;

    return data;
}

void    sll_print(void* list) {
    Node* current = ((List*) list)->head;

    printf("Single Linked List: ");

    while (current != NULL) {
        printf("%d", current->data);

        if (current->next != NULL) {
            printf(" --> ");
        }

        current = current->next;
    }

    printf("\n");
}
