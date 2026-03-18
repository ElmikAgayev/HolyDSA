#include <stdio.h>
#include "linked_list.h"
#include <stdlib.h>

void list_printer(PListNode node) {
	if(node->Data) printf("%d ", *(int*)(node->Data)); //Btw head node's data is empty
}

int main() {
	PListNode list = ListNew();
	int d = 1;
	ListPushBack(list, (void*)&d, sizeof(int));
	d = 2;
	ListPushBack(list, (void*)&d, sizeof(int));
	d = 3;
	ListPushBack(list, (void*)&d, sizeof(int));
	d = 4;
	ListPushBack(list, (void*)&d, sizeof(int));
	d = 5;
	ListPushBack(list, (void*)&d, sizeof(int));
	free(ListPopBack(list));

	ListForEach(list, list_printer); 

	return 0;
}
