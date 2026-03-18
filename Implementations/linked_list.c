#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "linked_list.h"

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

void *ListPopBack(PListNode l) {
	if(l->Next == l) return 0;
	while(l->Next != l->Next->Next) l = l->Next;
	void *d = l->Next->Data;
	l->Next = l;
	return d;
}

void ListForEach(PListNode l, void(*callback)(PListNode)) {
	while(l->Next != l) {
		callback(l);
		l = l->Next;
	} callback(l); // last element
}
