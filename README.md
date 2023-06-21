# simple-c-lists
A minuscule C library for [singly linked list](https://en.wikipedia.org/wiki/Linked_list#Singly_linked_list) support. Consists of some functions and a linked list data type.

## Documentation

### ```LL```
Data type for the linked lists

### ```void initll(LL *empty, int maxlen)```
After decleration, initalizes the linked list by allocating maxlen amount of memory.

### ```void deletell(LL *list)```
Frees the allocated memory.

### ```void convertarray(LL *empty, int arr[], int arrlen, int maxlen)```
Converts an ordinary C array to a linked list without changing the order. 

### ```void printll(LL list)```
For DEBUG purpuose. Prints list to show index, data, link (next index) values.

### ```int llinsert(LL *list, int data, int linkindex)```
Inserts data to selected index of list.

