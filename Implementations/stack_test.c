#include <stdio.h>
#include "stack.h"

void stack_print(PDataItem i) {
    static int c = 1;
    printf("%d. data-> %d\n", c++, *(int*)(i->Data));
}

int main() {
    PStack s = StackInit();
    int a = 1;
    StackPush(s, &a, sizeof(a));
    int b = 2;
    StackPush(s, &b, sizeof(b));
    int c = 3;
    StackPush(s, &c, sizeof(c));
    int d = 4;
    StackPush(s, &d, sizeof(d));
    StackPop(s);
    int e = 5;
    StackPush(s, &e, sizeof(e));

    StackForEach(s, stack_print);
    return EXIT_SUCCESS;
}