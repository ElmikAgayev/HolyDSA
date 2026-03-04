#include <stdio.h>
#include "linked_list.h"

void list_printer(PListNode node) {
	printf("%d ", *(int*)node->Data);
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
	
	ListForEach(list, list_printer); 

	return 0;
}
