#include <stdlib.h>

typedef struct data_item {
    void* Data;
    int DataSize;
    struct data_item* Next;
} DataItem, *PDataItem;

typedef struct {
    PDataItem Head;    
    int Size;
} Stack, *PStack;

PStack StackInit();
void StackPush(PStack s, void* data, int dataSize);
PDataItem StackPop(PStack s);
void StactRelease(PStack s);
int StackGetSize(PStack s);
void StackForEach(PStack s, void (*callback)(PDataItem));