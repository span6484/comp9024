// Binary Search Tree ADT implementation ... COMP9024 21T3

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include "BST.h"

#define RANDOM_ROOT_INSERT (rand() % 10 < 4)   // 40% chance

#define data(tree)  ((tree)->data)
#define left(tree)  ((tree)->left)
#define right(tree) ((tree)->right)

// modify the Node struct
typedef struct Node {
    bool deleted;
    Item data;
    Tree left, right;

    // auxiliary fields for drawing
    unsigned int height;
    unsigned int width;
    unsigned int drawWidth; // width including margin and node data length
    unsigned int drawPos;   // node data position relative to the left side of the tree
} Node;

// make a new node containing data
Tree newNode(Item it) {
    Tree new = malloc(sizeof(Node));
    assert(new != NULL);
    data(new) = it;
    left(new) = right(new) = NULL;
    new->deleted = false;
    return new;
}

// create a new empty Tree
Tree newTree() {
    return NULL;
}

// free memory associated with Tree
void freeTree(Tree t) {
    if (t != NULL) {
        freeTree(left(t));
        freeTree(right(t));
        free(t);
    }
}

// compute height of Tree
int TreeHeight(Tree t) {
    if (t == NULL) {
        return -1;
    } else {
        int lheight = 1 + TreeHeight(left(t));
        int rheight = 1 + TreeHeight(right(t));
        if (lheight > rheight)
            return lheight;
        else
            return rheight;
    }
}

// count #nodes in Tree
int TreeNumNodes(Tree t) {
    if (t == NULL)
        return 0;
    else
        return 1 + TreeNumNodes(left(t)) + TreeNumNodes(right(t));
}

// modify this file
// check whether a key is in a Tree
bool TreeSearch(Tree t, Item it) {
    if (t == NULL)
        return false;
    else if (it < data(t))
        return TreeSearch(left(t), it);
    else if (it > data(t))
        return TreeSearch(right(t), it);
    if (t->deleted == true)
        return false;
    else
        return true;
}

// insert a new item into a Tree
Tree TreeInsert(Tree t, Item it) {
    if (t == NULL)
        t = newNode(it);
    else if (it < data(t))
        left(t) = TreeInsert(left(t), it);
    else if (it > data(t))
        right(t) = TreeInsert(right(t), it);
    else if (it == data(t))
        if (t->deleted == true)
            t->deleted = false;
    return t;
}

Tree joinTrees(Tree t1, Tree t2) {
    if (t1 == NULL)
        return t2;
    else if (t2 == NULL)
        return t1;
    else {
        Tree curr = t2;
        Tree parent = NULL;
        while (left(curr) != NULL) {    // find min element in t2
            parent = curr;
            curr = left(curr);
        }
        if (parent != NULL) {
            left(parent) = right(curr);  // unlink min element from parent
            right(curr) = t2;
        }
        left(curr) = t1;
        return curr;                    // min element is new root
    }
}

// modify this file
// delete an item from a Tree
Tree TreeDelete(Tree t, Item it) {
    if (t != NULL) {
        if (it < data(t))
            left(t) = TreeDelete(left(t), it);
        else if (it > data(t))
            right(t) = TreeDelete(right(t), it);
        else {
            t->deleted = true;
        }
    }
    return t;
}

Tree rotateRight(Tree n1) {
    if (n1 == NULL || left(n1) == NULL)
        return n1;
    Tree n2 = left(n1);
    left(n1) = right(n2);
    right(n2) = n1;
    return n2;
}

Tree rotateLeft(Tree n2) {
    if (n2 == NULL || right(n2) == NULL)
        return n2;
    Tree n1 = right(n2);
    right(n2) = left(n1);
    left(n1) = n2;
    return n1;
}

Tree insertAtRoot(Tree t, Item it) {
    if (t == NULL) {
        t = newNode(it);
    } else if (it < data(t)) {
        left(t) = insertAtRoot(left(t), it);
        t = rotateRight(t);
    } else if (it > data(t)) {
        right(t) = insertAtRoot(right(t), it);
        t = rotateLeft(t);
    }
    return t;
}

Tree insertRandom(Tree t, Item it) {
    if (t == NULL)
        t = newNode(it);
    if (RANDOM_ROOT_INSERT)
        return insertAtRoot(t, it);
    else
        return TreeInsert(t, it);
}

Tree insertAVL(Tree t, Item it) {
    if (t == NULL)
        return newNode(it);
    if (it == data(t))
        return t;

    if (it < data(t))
        left(t) = insertAVL(left(t), it);
    else
        right(t) = insertAVL(right(t), it);

    int hL = TreeHeight(left(t));
    int hR = TreeHeight(right(t));
    if ((hL - hR) > 1) {
        if (it > data(left(t))) {
            left(t) = rotateLeft(left(t));
        }
        t = rotateRight(t);
    } else if ((hR - hL) > 1) {
        if (it < data(right(t))) {
            right(t) = rotateRight(right(t));
        }
        t = rotateLeft(t);
    }

    return t;
}

Tree insertSplay(Tree t, Item it) {
    if (t == NULL)
        return newNode(it);
    if (it == data(t))
        return t;

    if (it < data(t)) {
        if (left(t) == NULL) {
            left(t) = newNode(it);
        } else if (it < data(left(t))) {
            left(left(t)) = insertSplay(left(left(t)), it);
            t = rotateRight(t);
        } else if (it > data(left(t))) {
            right(left(t)) = insertSplay(right(left(t)), it);
            left(t) = rotateLeft(left(t));
        }
        return rotateRight(t);
    } else {
        if (right(t) == NULL) {
            right(t) = newNode(it);
        } else if (it < data(right(t))) {
            left(right(t)) = insertSplay(left(right(t)), it);
            right(t) = rotateRight(right(t));
        } else if (it > data(right(t))) {
            right(right(t)) = insertSplay(right(right(t)), it);
            t = rotateLeft(t);
        }
        return rotateLeft(t);
    }
}

Tree partition(Tree t, int i) {
    if (t != NULL) {
        assert(0 <= i && i < TreeNumNodes(t));
        int m = TreeNumNodes(left(t));
        if (i < m) {
            left(t) = partition(left(t), i);
            t = rotateRight(t);
        } else if (i > m) {
            right(t) = partition(right(t), i-m-1);
            t = rotateLeft(t);
        }
    }
    return t;
}

Tree rebalance(Tree t) {
    int n = TreeNumNodes(t);

    if (n >= 3) {
        t = partition(t, n/2);           // put node with median key at root
        left(t) = rebalance(left(t));    // then rebalance each subtree
        right(t) = rebalance(right(t));
    }
    return t;
}

// display tree, solution by Jason Liu

const unsigned int vMargin = 0; // extra number of lines between levels
const unsigned int hMargin = 0; // number of columns between nodes
const char leftEdge = '/';
const char rightEdge = '\\';
const char hEdge = '_';
const char vEdge = '|';

int numDigits(int number) {
    int digits = ceil(log10(abs(number) + 1));
    return number <= 0 ? digits + 1 : digits;
}

void calculateProperties(Tree t) {
    if (t == NULL) {
        return;
    }

    int leftHeight = -1;
    int rightHeight = -1;
    int leftWidth = 0;
    int rightWidth = 0;
    int leftDrawWidth = 0;
    int rightDrawWidth = 0;

    if (left(t) != NULL) {
        calculateProperties(left(t));
        leftHeight = left(t)->height;
        leftWidth = left(t)->width;
        leftDrawWidth = left(t)->drawWidth + hMargin;
    }

    if (right(t) != NULL) {
        calculateProperties(right(t));
        rightHeight = right(t)->height;
        rightWidth = right(t)->width;
        rightDrawWidth = right(t)->drawWidth + hMargin;
    }

    t->height = fmax(leftHeight, rightHeight) + 1;
    t->width = leftWidth + rightWidth + 1;
    t->drawWidth = leftDrawWidth + numDigits(data(t)) + rightDrawWidth;
    t->drawPos = leftDrawWidth;
}

void drawData(Tree t, char* line, int hOffset) {
    int currNum = abs(data(t));
    int digits = numDigits(data(t));
    int pos = hOffset + t->drawPos + digits - 1;

    if (currNum == 0) {
        line[pos] = '0';
        return;
    }
    // converts int to char from least significant digit
    while (currNum > 0) {
        int d = currNum % 10;
        line[pos] = d + '0';
        currNum /= 10;
        pos--;
    }

    if (data(t) < 0) {
        line[pos] = '-';
    }
}

void drawLeftEdge(Tree t, char** grid, int vOffset, int hOffset) {
    if (left(t) == NULL) {
        return;
    }

    int hPos = hOffset + t->drawPos;
    int vPos = vOffset + 1;
    grid[vPos][hPos] = grid[vPos][hPos] != rightEdge ? leftEdge : vEdge; // draw left pointing line below the root
    hPos--;
    int hGoal = hOffset + left(t)->drawPos + numDigits(data(left(t))) / 2;

    // draw horizontal and vertical lines connecting to left child
    while (hPos > hGoal) {
        grid[vPos][hPos] = hEdge;
        hPos--;
    }

    vPos++;
    int vGoal = vOffset + vMargin + 2;

    while (vPos < vGoal) {
        grid[vPos][hPos] = vEdge;
        vPos++;
    }

    grid[vPos][hPos] = leftEdge; // draw left pointing line above the left child
}

void drawRightEdge(Tree t, char** grid, int vOffset, int hOffset) {
    if (right(t) == NULL) {
        return;
    }

    int hPos = hOffset + t->drawPos + numDigits(data(t)) - 1;
    int vPos = vOffset + 1;
    grid[vPos][hPos] = grid[vPos][hPos] != leftEdge ? rightEdge : vEdge;
    hPos++;
    int hGoal = hPos + hMargin + right(t)->drawPos + fmax(numDigits(data(right(t))) / 2 - 1, 0);

    while (hPos < hGoal) {
        grid[vPos][hPos] = hEdge;
        hPos++;
    }

    vPos++;
    int vGoal = vOffset + vMargin + 2;

    while (vPos < vGoal) {
        grid[vPos][hPos] = vEdge;
        vPos++;
    }

    grid[vPos][hPos] = rightEdge;
}

void drawTree(Tree t, char** grid, int vOffset, int hOffset) {
    if (t == NULL) {
        return;
    }

    drawData(t, grid[vOffset], hOffset);
    drawLeftEdge(t, grid, vOffset, hOffset);
    drawRightEdge(t, grid, vOffset, hOffset);
    int newVOffset = vOffset + vMargin + 3;
    drawTree(left(t), grid, newVOffset, hOffset);
    drawTree(right(t), grid, newVOffset, hOffset + t->drawPos + numDigits(data(t)) + hMargin);
}

void showTreeD(Tree t) {
    if (t == NULL) {
        return;
    }

    int h = t->height * (vMargin + 3) + 1; // put a minimum of 2 lines between levels
    int w = t->drawWidth;
    char** grid = malloc(h * sizeof(char*));
    assert(grid != NULL);

    for (int i = 0; i < h; i++) {
        grid[i] = malloc(w * sizeof(char));
        assert(grid[i] != NULL);

        for (int j = 0; j < w; j++) {
            grid[i][j] = ' ';
        }
    }

    drawTree(t, grid, 0, 0);

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            putchar(grid[i][j]);
        }

        putchar('\n');
        free(grid[i]);
    }

    free(grid);
}

void showTree(Tree t) {
    calculateProperties(t);
    showTreeD(t);
}