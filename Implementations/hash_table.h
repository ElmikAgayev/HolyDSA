#include <stdlib.h>
#include <string.h>
#include "linked_list.h"

typedef struct {
	char *Key;
	void *Data;
	PListNode Next;
} HashTableNode, *PHashTableNode;

typedef struct {
	HashTableNode* Table;
	unsigned int Size;
} HastTable, *PHashTable;

PHashTable HashTableInit();
PHashTableNode HashTableFind(PHashTable t, const char *key);
void HashTableInsert(PHashTable t, const char *key, void *Data);
void HashTableDelete(PHashTable t, const char *key);
