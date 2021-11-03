//
// Created by shao on 2021/10/4.
//

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include "string.h"
#include "assert.h"
typedef struct node {
    int data;
    struct node *next;
}NodeT;

void showLL(NodeT *list);
NodeT *joinLL(NodeT *list, int v);

// create node
NodeT *createNode(int v) {
    NodeT *newNode = malloc(sizeof(newNode));
    newNode->next = NULL;
    newNode->data = v;
    return newNode;
}

//join
//returns a pointer to the linked list obtained by appending
// a new element with data v at the end of list. Needs to be implemented.
NodeT *joinLL(NodeT *list, int v){
    NodeT *cur = list;
    if(list == NULL){
        list = createNode(v);
        return list;
    }

    else {
        while(cur->next != NULL){
            cur = cur->next;
        }
        NodeT *newNode = createNode(v);
        cur->next = newNode;
        return list;
        }
}
//modify show
void showLL(NodeT *list) {
    NodeT *p;
    for (p = list; p->next!= NULL; p = p->next) {
        printf("%d-->", p->data);
    }
    printf("%d\n",p->data);
}
//free, from lecture
void freeLL(NodeT *list) {
    NodeT *p, *temp;
    p = list;
    while (p != NULL) {
        temp = p->next;
        free(p);
        p = temp;
    }
}


int main(int argc, char *argv[]) {
    int val;
    char str[100];
    NodeT *header = NULL;
    while(1) {
        printf("Enter a number: ");
        if(scanf("%s",str) == 1) {
            if(strcmp(str,"#") == 0){
                printf("Done. List is ");
                break;
            }
            if(strcmp(str,"quit") == 0){
                printf("Done.\n");
                break;
            }
            val = atoi(str);
            header = joinLL(header, val);
        }
    }
    showLL(header);
    freeLL(header);
    return 0;
}


