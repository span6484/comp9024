// Linked list implementation ... COMP9024 21T3
#include "list.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


Node *makeNode(char *n) {
    Node *new = malloc(sizeof(Node));

    assert(new != NULL);
    strcpy(new->v, n);
    new->next = NULL;

    return new;
}

List insertLL(List L, char* n) {
    if (inLL(L, n))
        return L;

    // add new node at the beginning
    Node *new = makeNode(n);

    if(L == NULL) {
        L = new;
        return L;
    }
    List cur = L;
    while(cur->next != NULL) {
        cur = cur->next;
    }
    cur->next = new;
    return L;
}

List deleteLL(List L, char* n) {
    if (L == NULL) {
        return L;
    } else if (L->v == n) {
        Node *p = L->next;
        free(L);
        return p;
    } else {
        L->next = deleteLL(L->next, n);
        return L;
    }
}

bool inLL(List L, char* n) {
    if (L == NULL)
        return false;
    if (strcmp(L->v,n) == 0)
        return true;

    return inLL(L->next, n);
}

void showLL(List L) {
    if (L == NULL)
        putchar('\n');
    else {
        printf("%s ", L->v);
        showLL(L->next);
    }
}

void freeLL(List L) {
    if (L != NULL) {
        freeLL(L->next);
        free(L);
    }
}

bool compareTwoStr(List L, char *n) {
    List cur = L->next;
    bool is_satisfy;   //0: false 1: true
    while(cur != NULL){
        is_satisfy = true;
        if(strlen(cur->v) == strlen(n)) {
            for(int i = 0; i < strlen(n); i++) {
                if(cur->v[i] == '%') continue;
                else if(cur->v[i] != n[i]){
                    is_satisfy = false;
                    break;
                }
            }
            if(is_satisfy) {
//                printf("%s %s %d %d\n",L,n,strlen(cur->v),strlen(n));
                return true;
            }
        }
        cur = cur->next;
    }

    return false;
}