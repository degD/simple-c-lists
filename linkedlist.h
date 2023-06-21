
#ifndef LL_H
#define LL_H

typedef struct linkedlist {
	int length;
	int head;
	int *data_array;
	int *link_array;
} LL;

void initll(LL *empty, int maxlen);
void deletell(LL *list);
void convertarray(LL *empty, int arr[], int arrlen, int maxlen);
void printll(LL list);
int llinsert(LL *list, int data, int linkindex);
int llremove(LL *list, int linkindex);
int llitem(LL list, int linkindex);
int llreplace(LL *list, int linkindex, int newdata);
int llpop(LL *list);
void llappend(LL *list, int newdata);

#endif