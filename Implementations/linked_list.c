#include <stdlib.h>
#include "linked_list.h"
#include <string.h>
#include <stdio.h>

PListNode ListNew() {
	PListNode l = (PListNode)calloc(sizeof(ListNode), 1);
	l->Next = l;
	return l;
}

void ListPushBack(PListNode l, void *data, int data_size) {
	PListNode n = (PListNode)calloc(sizeof(ListNode), 1);
	n->Data = (void*)calloc(data_size, 1);
	memcpy(n->Data, data, data_size);
	n->DataSize = data_size;
	n->Next = n;
	
	while(l->Next != l) l = l->Next;

	l->Next = n; 
}

void ListForEach(PListNode l, void(*callback)(PListNode)) {
	do {
		callback(l);
		l = l->Next;
	} while(l->Next != l);
}
