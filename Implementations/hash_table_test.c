#include "hash_table.h"

int main() {
	PHashTable table = HashTableInit();
	int data1 = 0xBEEF;
	HashTableInsert(table, "key1", &data1); 
	return 0;
}
