#include <stdlib.h>

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct sNode {
    struct sNode * prev;
    struct sNode * next;

    int value;
} * Node;

typedef struct sLinkedList {
    struct sNode * head;
    struct sNode * tail;

    int length;
} * LinkedList; 

LinkedList init_list();

Node init_node(int value);

int getAt(LinkedList list, int index);

void append(LinkedList list, int value);

void prepend(LinkedList list, int value);

void insertAt(LinkedList list, int index, int value);

void removeAt(LinkedList list, int index);

#endif
