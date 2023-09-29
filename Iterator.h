#include <stdlib.h>
#include <stdbool.h>

#include "LinkedList.h"

#ifndef ITERATOR_H
#define ITERATOR_H

typedef struct sIterator {
    LinkedList list;
    Node current;
} * Iterator;

Iterator init_iterator(LinkedList list);

bool hasNext(Iterator iterator);

Node next(Iterator iterator);

void reset(Iterator iterator);

bool advanceBy(Iterator iterator, int terms);

Iterator chain(Iterator iterator1, Iterator iterator2);

LinkedList collect(Iterator iterator);

Iterator map(Iterator iterator, int (* func)(int));

Iterator filter(Iterator iterator, bool (* func)(int));

int reduce(Iterator iterator, int (* func)(int, int));

#endif
