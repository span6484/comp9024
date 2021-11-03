//
// Created by shao on 2021/10/13.
//

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "stack.h"


typedef struct NodeRep {
    int data;
    Node next;
}NodeRep;

typedef struct StackRep {
    int height;     //elements on stack
    Node top;
}StackRep;


Stack newStack(){
    Stack s = malloc(sizeof (StackRep));
    assert(s != NULL);
    s->height = 0;
    s->top = NULL;
    return s;
}

// insert an int on top of stack
void StackPush(Stack s, int val) {
    assert(s != NULL);
    Node n = malloc(sizeof (NodeRep));
    assert( n != NULL);
    n->data = val;
    n->next = s->top;
    s->top = n;
    s->height++;
}

// print the stacks val;
void printStack(Stack s) {
    assert(s != NULL);
    Node cur = s->top;
    while(cur->next != NULL) {
        printf("%d\n",cur->data);
        printf("↓\n");
        cur = cur->next;
    }
    printf("%d\n",cur->data);
}

// remove int from top of stack
int StackPop(Stack s) {
    assert(s->height > 0);
    Node cur = s->top;
    s->top = s->top->next;
    int pop_val = cur->data;
    s->height--;
    free(cur);
    return pop_val;
}
//remove unwanted stack
void dropStack(Stack s){
    assert(s != NULL);

    Node cur = s->top;
    while(cur != NULL) {
        Node temp = cur->next;
        free(cur);
        cur = temp;
        s->height--;
    }
    free(s);
}

bool StackIsEmpty(Stack s) {
    printf("%d\n", s->height);
    if (s->top == NULL) {
        printf("stack is empty\n");
        return true;
    }
    printf("%d\n", s->top->data);
    printf("stack is not empty\n");
    return false;

}