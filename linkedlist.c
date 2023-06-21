#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

void initll(LL *empty, int maxlen)
{
	empty->length = 0;
	empty->head = 0;
	empty->data_array = (int*)calloc(maxlen, sizeof(int));
	empty->link_array = (int*)calloc(maxlen, sizeof(int));
}

void deletell(LL *list)
{
	free(list->data_array);
	free(list->link_array);
}

void convertarray(LL *empty, int arr[], int arrlen, int maxlen)
{
	int i;
	
	initll(empty, maxlen);
	empty->length = arrlen;
	
	for (i = 0; i < arrlen; i++) {
		empty->data_array[i] = arr[i];
		empty->link_array[i] = i+1;
	}
	empty->link_array[i-1] = -1;
}

void printll(LL list)
{
	int i = list.head;
	printf("index\tdata\tlink\n");
	while (list.link_array[i] != -1) {
		printf("% d\t% d\t% d\n", i, list.data_array[i], list.link_array[i]);
		i = list.link_array[i];
	}
	printf("% d\t% d\t% d\n", i, list.data_array[i], list.link_array[i]);
}

int llinsert(LL *list, int data, int linkindex)
{
	int i = list->head, c = 0, len = list->length;
	
	if (linkindex == 0) {
		list->data_array[len] = data;
		list->link_array[len] = list->head;
		list->head = len;	
		list->length++;	
		return 0;	
	}
	
	if (linkindex > len) {
		return 1;
	} 
	else {
		while (c++ < linkindex-1) i = list->link_array[i];
		
		list->data_array[len] = data;
		list->link_array[len] = list->link_array[i];
		list->link_array[i] = len;	
		list->length++;	
		
		return 0;	
	}
}

int llremove(LL *list, int linkindex)
{
	int c = 0;
	int i = list->head, next_i;

	if (linkindex == 0) {
		list->head = list->link_array[i];
		list->length--;
		return 0;
	}

	if (linkindex > list->length) {
		return 1;
	} else {
		while (c++ < linkindex-1) i = list->link_array[i];

		next_i = list->link_array[i];
		list->link_array[i] = list->link_array[next_i]; 
		list->length--;

		return 0;
	}
} 

int llitem(LL list, int linkindex)
{
	int c = 0, i = list.head;

	if (linkindex < list.length) {
		while (c++ < linkindex) i = list.link_array[i];
		return list.data_array[i];
	}
	return -1;
}
   
int llreplace(LL *list, int linkindex, int newdata)
{
	int c = 0, i = list->head;

	if (linkindex < list->length) {
		while (c++ < linkindex) i = list->link_array[i];
		list->data_array[i] = newdata;
		return 0;
	}
	return -1;
}

int llpop(LL *list)
{
	int prev_i, i = list->head;

	while (list->link_array[i] != -1) {
		prev_i = i;
		i = list->link_array[i];
	}

	list->length--;
	list->link_array[prev_i] = -1;
	return list->data_array[i];
}

void llappend(LL *list, int newdata)
{
	int i = list->head;

	while (list->link_array[i] != -1)
		i = list->link_array[i];

	list->data_array[list->length] = newdata;
	list->link_array[list->length] = -1;
	list->link_array[i] = list->length;
	list->length++;
}