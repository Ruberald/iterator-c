
# An Iterator in C

A simple iterator in C using a linked list.

#### Functions implemented:

* hasNext
* next
* advanceBy
* chain
* collect
* map
* filter
* reduce

### Example

Run the provided example in ___examples/___ to get the following output.

```
$ gcc -g examples/main.c Iterator.c LinkedList.c -o examples/main
$ ./examples/main
Chained iterator: 3     4       7       10      7       8
Filtered iterator: 4    10      8
Mapped iterator: 6      8       14      20      14      16
Reduced iterator: 39
```


