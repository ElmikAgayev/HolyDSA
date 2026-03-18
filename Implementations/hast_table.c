#include "hash_table.h"

#define HashFunc meiyan

static int meiyan(const char *key, int count) {
	typedef int* P;
	int h = 0x811c9dc5;
	while (count >= 8) {
		h = (h ^ ((((*(P)key) << 5) | ((*(P)key) >> 27)) ^ *(P)(key + 4))) * 0xad3e7;
		count -= 8;
		key += 8;
	}
	#define tmp h = (h ^ *(short*)key) * 0xad3e7; key += 2;
	if (count & 4) { tmp tmp }
	if (count & 2) { tmp }
	if (count & 1) { h = (h ^ *key) * 0xad3e7; }
	#undef tmp
	return h ^ (h >> 16);
}

PHashTable HashTableInit(int size) {
	PHashTable t = calloc(1, sizeof(HashTable)); assert(t);
	t->Table = calloc(1, sizeof(HashTableNode) * size); assert(t->Table);
	t->Size = size;
	t->Count = 0;
	t->GrowthFactor = 10;
	t->GrowthTreshold = 2.0;
	return t;
}

static void HashTableResize(PHashTable t, int newSize) {
	PHashTable n = calloc(1, sizeof(HashTable)); assert(n);
	n->Table = calloc(1, sizeof(PHashTableNode) * newSize);
	n->Count = t->Count;
	n->Size = newSize;
	n->GrowthFactor = t->GrowthFactor;
	n->GrowthTreshold = t->GrowthTreshold;
	
	for(unsigned int i = 0; i < t->Size; i++) {
		PHashTableNode c = t->Table[i];
		do { //TODO: Fix linked list reinsert issue
			n->Table[i] = t->Table[i];
			c = c->Next;
		}
		while(c->Next != c);
	}

	free(t);
}

void HashTableInsert(PHashTable t, const char *key, void *data, unsigned long long dataSize) {
	int n = HashFunc(key, strlen(key)) % t->Size;
	if(t->Table[n] == 0) {
		double f = (double)t->Count / (double) t->Size;
		if(f > t->GrowthTreshold) {

		}
	}
}