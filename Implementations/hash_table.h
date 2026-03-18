#include <stdlib.h>
#include <string.h>
#include "linked_list.h"

#define DEFAULT_HASH_TABLE_SIZE 1024

typedef struct {
	char *Key;
	void *Data;
	unsigned long long DataSize;
	PListNode Next;
} HashTableNode, *PHashTableNode;

typedef struct {
	PHashTableNode* Table;
	unsigned int Size, Count;
	double GrowthTreshold, GrowthFactor;
} HashTable, *PHashTable;

PHashTable HashTableInit(int size);
PHashTableNode HashTableFind(PHashTable t, const char *key);
void HashTableInsert(PHashTable t, const char *key, void *data, unsigned long long dataSize);
void HashTableDelete(PHashTable t, const char *key);
void HashTableForEach(PHashTable t, void(*callback)(PHashTableNode));