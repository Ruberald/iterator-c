#include <stdbool.h>
#include <stdio.h>

#include "../Iterator.h"

bool is_even(int num) {
    return (num % 2 == 0);
}

int double_num(int num) {
    return (num * 2);
}

int sum(int a, int b) {
    return (a + b);
}

int main() {
    LinkedList list1 = init_list();

    append(list1, 3);
    append(list1, 4);
    append(list1, 7);

    LinkedList list2 = init_list();

    append(list2, 10);
    append(list2, 7);
    append(list2, 8);

    Iterator iterator = chain(init_iterator(list1), init_iterator(list2));

    printf("Chained iterator: ");
    while(hasNext(iterator)) {
        printf("%d\t", next(iterator)->value);
    }

    reset(iterator);

    Iterator filteredIterator = filter(iterator, is_even);

    printf("\nFiltered iterator: ");
    while(hasNext(filteredIterator)) {
        printf("%d\t", next(filteredIterator)->value);
    }

    reset(iterator);

    Iterator mappedIterator = map(iterator, double_num);

    printf("\nMapped iterator: ");
    while(hasNext(mappedIterator)) {
        printf("%d\t", next(mappedIterator)->value);
    }

    reset(iterator);

    printf("\nReduced iterator: %d", reduce(iterator, sum));
}
