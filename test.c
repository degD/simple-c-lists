#include <stdio.h>
#include "linkedlist.h"

#define MAX 100

int main()
{
	int i, arr[5] = {1, 3, 5, 2, 7};
	LL list;
	
	printf("Linked-List TEST\n\n");
	
	/* Convert an ordinary array to a linked list */
	convertarray(&list, arr, 5, MAX);
	printll(list);

	/* Insert the number "15" to index "0" */
	llinsert(&list, 15, 0);
	printll(list);

	/* Remove the number at the index "0" */
	llremove(&list, 0);
	printll(list);
	
	/* Print numbers ordered by their linked-list indexes */
	for (i = 0; i < 5; i++)
		printf("%d -> %d\n", i, llitem(list, i));

	/* Replace index "0" with number "200" */
	llreplace(&list, 0, 200);
	printll(list);

	/* Remove and return (Pop) the last elemant from list (In our case, "7") */
	printf("%d was the last!\n", llpop(&list));

	/* Append "400, 600, 800" respectively to the end of the list */
	llappend(&list, 400);
	llappend(&list, 600);
	llappend(&list, 800);
	printll(list);

	/* Free the memory used by the list */
	deletell(&list);
	
	return 0;
}
