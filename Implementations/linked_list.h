typedef struct _list_node {
	struct _list_node *Next;
	void *Data;
	int DataSize;
} ListNode, *PListNode;

PListNode ListNew();
void ListPushBack(PListNode l, void *data, int data_size);
void ListForEach(PListNode l, void(*callback)(PListNode));
void *ListPopBack(PListNode l);
