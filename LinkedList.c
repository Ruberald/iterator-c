#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"

LinkedList init_list() {
    LinkedList list = (LinkedList) malloc(sizeof(struct sLinkedList));
    list->head = list->tail = NULL;
    list->length = 0;

    return list;
}

Node init_node(int value) {
    Node node = (Node) malloc(sizeof(struct sNode));
    node->value = value;
    node->next = node->prev = NULL;

    return node;
}

int getAt(LinkedList list, int index) {
    Node current = list->head;

    for (int i = 0; i < index; ++i) {
        current = current->next;
    }

    return current->value;
}

void append(LinkedList list, int value) {
    Node node = init_node(value);

    list->length++;

    if(list->tail == NULL) {
        list->head = list->tail = node;
        return;
    }

    list->tail->next = node;
    node->prev = list->tail;
    list->tail = node;
}

void prepend(LinkedList list, int value) {
    Node node = init_node(value);

    list->length++;

    if(list->head == NULL) {
        list->head = list->tail = node;
        return;
    }

    list->head->prev = node;
    node->next = list->head;
    list->head = node;
}

void insertAt(LinkedList list, int index, int value) {
    Node current = list->head;

    for (int i = 0; i < index; ++i) {
        current = current->next;
    }
    
    Node node = init_node(value);

    list->length++;

    node->next = current;
    node->prev = current->prev;
    current->prev = node;
    node->prev->next = node;
}

void removeAt(LinkedList list, int index) {
    Node current = list->head;

    for (int i = 0; i < index; ++i) {
        current = current->next;
    }

    list->length--;

    current->prev->next = current->next;
    current->next->prev = current->prev;

    free(current);
}
