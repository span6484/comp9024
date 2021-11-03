// Linked list interface ... COMP9024 21T3
#include <stdbool.h>

typedef struct Node *List;
typedef struct Node {
    char v[40];
    struct Node *next;
} Node;
List insertLL(List, char*);
List deleteLL(List, char*);
bool inLL(List, char*);
void freeLL(List);
void showLL(List);
bool compareTwoStr(List L, char *n);