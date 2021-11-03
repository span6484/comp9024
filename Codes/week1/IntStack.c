//
// Created by shao on 2021/9/21.
//

#include "IntStack.h"

typedef struct {
    char item[MAXITEMS];
    int top;
} stackRep;

static stackRep stackObject;
void StackInit() {
    stackObject.top = -1;
}

int StackIsEmpty() {
    return (stackObject.top < 0);
}

void StackPush(char ch) {
    assert(stackObject.top < MAXITEMS - 1);
    stackObject.top++;
    int i = stackObject.top;
    stackObject.item[i] = ch;
}

char StackPop() {
    assert(stackObject.top > -1);
    int i = stackObject.top;
    char ch = stackObject.item[i];
    stackObject.top--;
    return ch;
}

int main(void)
{
    StackInit();
    printf("%d\n", stackObject.top);
    printf("%s",stackObject.item);
    StackPush('b');
    StackPop();
    printf("%s",stackObject.item);
    return 0;
}