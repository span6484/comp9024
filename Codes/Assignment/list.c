// Linked list implementation ... COMP9024 21T3
#include "list.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


bool isContainBoth(char *str1, char *str2);

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

// make sure both side not has % at once
bool isContainBoth(char *str1, char *str2) {
    int i;
    bool in_str1 = false;
    bool in_str2 = false;
    for(i = 0; i < strlen(str1); i++) {
        if (str1[i] == '%') {
            in_str1 = true;
            break;
        }
    }
    for(i = 0; i < strlen(str2); i++) {
        if (str2[i] == '%') {
            in_str2 = true;
            break;
        }
    }
    if (in_str1 == true && in_str2 == true) {
        return true;
    }
    return false;
}

bool compareTwoStr(List L, List L2) {
    List cur = L;
    List cur2;
    bool is_satisfy;   //0: false 1: true


    while(cur != NULL){
        cur2 = L2;
        while(cur2 != NULL) {
            is_satisfy = true;
//            printf("Now compare %s %s\n\n", cur->v,cur2->v);
            if (strlen(cur->v) == strlen(cur2->v)) {
                for (int i = 0; i < strlen(cur->v); i++) {
                    if (isContainBoth(cur->v,cur2->v) == true) {
//                        printf("!!!!!!danger %s %s\n",cur->v,cur2->v);
                        is_satisfy = false;
                        break;
                    }
                    if (cur->v[i] != cur2->v[i]) {
                         if (cur->v[i] != '%' && cur2->v[i] != '%'){
                             is_satisfy = false;
//                             printf("here is the problem: %s %s  %c %c\n", cur->v, cur2->v,cur->v[i],cur2->v[i]);
                             break;
                         }
                    }
                }
//                printf("%s %s %d %d boolean: %d\n",cur->v,cur2->v,strlen(cur->v),strlen(cur2->v), is_satisfy);
                if (is_satisfy) {
//                    printf("the are true\n");
                    return true;
                }
            }
            cur2 = cur2->next;
        }
        cur = cur->next;
    }

    return false;
}