#include "stack.h"

PStack StackInit() {
    PStack s = (PStack)malloc(sizeof(Stack)); s->Size = 0;
    if (s != NULL) {
        s->Head = (PDataItem)malloc(sizeof(DataItem));
        if (s->Head) {
            s->Head->Data = NULL;
            s->Head->DataSize = 0;
            s->Head->Next = s->Head;
        }
        else {
            //TODO: proper error handling
        }
    }
    else {
        //TODO: proper error handling
    }
    return s;
}

void StackPush(PStack s, void* data, int dataSize) {
    if (s == NULL) return;

    PDataItem c = s->Head;
    while (c->Next != s->Head) c = c->Next;

    c->Next = (PDataItem)malloc(sizeof(DataItem));
    if (c->Next) {
        c->Next->Next = s->Head;
        c->Next->Data = data;
        c->Next->DataSize = dataSize;
    }
    s->Size++;
}

PDataItem StackPop(PStack s) {
    if (s == NULL) return NULL;

    PDataItem c = s->Head;
    while (c->Next->Next != s->Head) c = c->Next;

    PDataItem r = c->Next;
    c->Next = r->Next;

    s->Size = (s->Size > 0) ? s->Size - 1: 0;

    return r;
}

void StactRelease(PStack s) {
    if (s != NULL) {
        PDataItem c = s->Head;
        while (c->Next != s->Head) {
            if (c->Data) free(c->Data);
            free(c);
        }
        free(c->Data);
        free(c);
        free(s);
    }
}

int StackGetSize(PStack s) { 
    if (s == NULL) return 0;
    return s->Size;
}

void StackForEach(PStack s, void (*callback)(PDataItem)) {
    PDataItem c = s->Head->Next;
    while (c != s->Head) {
        callback(c);
        c = c->Next;
    }
}