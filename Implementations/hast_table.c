#include "hash_table.h"

#define DEFAULT_HASH_TABLE_SIZE 1024

PHashTable HashTableInit() {
	PHashTable t = malloc(sizeof(HashTable)); assert(t);
	t->Table = calloc(1, sizeof(HashTableNode) * DEFAULT_HASH_TABLE_SIZE);
	t->Size = DEFAULT_HASH_TABLE_SIZE;
	return t;
}


