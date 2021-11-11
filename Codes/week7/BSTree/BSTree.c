//
// Created by shao on 2021/11/6.
//

#include <stdlib.h>
#include <assert.h>
#include "BSTree.h"

#define data(tree) ((tree)->data)
#define left(tree) ((tree)->left)
#define right(tree) ((tree) ->right)

typedef struct Node {
    Item data;
    Tree left, right;
} Node;

Tree newNode(Item it) {
    Tree new = malloc(sizeof(Node));
    assert(new != NULL);
    data(new) = it;
    left(new) = right(new) = NULL;
    return new;
}

Tree newTree() {
    return NULL;
}

void freeTree(Tree t) {
    if (t != NULL) {
        freeTree(left(t));
        freeTree(right(t));
        free(t);
    }
}

int TreeHeight(Tree t) {
    return -1;
}

int TreeNumNodes(Tree t) {
    if (t == NULL)
        return 0;
    else
        return 1 + TreeNumNodes(left(t)) + TreeNumNodes(right(t));
}

bool TreeSearch(Tree t, Item it) {
    if (t == NULL)
        return false;
    else if (it < data(t))
        return TreeSearch(left(t), it);
    else
        return true;
}

// insert a new item into a Tree
Tree TreeInsert(Tree t, Item it) {
    if (t == NULL) {
        t = newNode(it);
    }
    else if (it < data(t))
        left(t) = TreeInsert(left(t), it);
    else if (it > data(t))
        right(t) = TreeInsert(right(t), it);
    return t;
}