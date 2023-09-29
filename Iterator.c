#include <stdlib.h>
#include <stdbool.h>

#include "LinkedList.h"
#include "Iterator.h"

Iterator init_iterator(LinkedList list) {
    Iterator iterator = (Iterator) malloc(sizeof(struct sIterator));

    iterator->list = list;
    iterator->current = list->head;

    return iterator;
}

bool hasNext(Iterator iterator) {
    return (iterator->current);
}

Node next(Iterator iterator) {
    if(!iterator->current) {
        return NULL;
    }

    Node node = iterator->current;
    iterator->current = iterator->current->next;

    return node;
}

void reset(Iterator iterator) {
    iterator->current = iterator->list->head;
}

bool advanceBy(Iterator iterator, int terms) {
    while(terms--) {
        iterator->current = iterator->current->next;
        if(!iterator->current) {
            return false;
        }
    }
    return true;
}

Iterator chain(Iterator iterator1, Iterator iterator2) {
    Iterator iterator = init_iterator(iterator1->list);

    iterator->list->tail->next = iterator2->list->head;
    iterator->list->tail = iterator2->list->tail;

    return iterator;
}

LinkedList collect(Iterator iterator) {
    return iterator->list;
}

Iterator map(Iterator iterator, int (* func)(int)) {
    LinkedList mappedList = init_list();

    while(hasNext(iterator)) {
        Node current = next(iterator);
        append(mappedList, func(current->value));
    }

    Iterator mappedIterator = init_iterator(mappedList);

    return mappedIterator;
}

Iterator filter(Iterator iterator, bool (* func)(int)) {
    LinkedList filteredList = init_list();

    while(hasNext(iterator)) {
        Node current = next(iterator);
        if(func(current->value)) {
            append(filteredList, current->value);
        }
    }

    Iterator filteredIterator = init_iterator(filteredList);

    return filteredIterator;
}

int reduce(Iterator iterator, int (* func)(int, int)) {
    if(iterator->list->length < 2) {
        return iterator->list->head->value;
    }

    int first_term = next(iterator)->value;
    int second_term = next(iterator)->value;
    int result = func(first_term, second_term);

    while(hasNext(iterator)) {
        int value = next(iterator)->value;
        result = func(result, value);
    }

    return result;
}
