

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "stack.h"

int main(void) {
    bool a;
    Stack s = newStack();
    a = StackIsEmpty(s);
    printf("%d\n",a);

    StackPush(s,1);
    StackPush(s,2);
//    a = StackIsEmpty(s);
//    printf("%d\n",a);
    StackPush(s,3);
    StackPush(s,4);
    StackPush(s,5);
//    dropStack(s);
//    printStack(s);
    return 0;
}