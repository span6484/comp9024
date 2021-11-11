#include <stdbool.h>

typedef int Item;

typedef struct Node *Tree;

Tree newTree();
void freeTree(Tree);
void showTree(Tree);

bool TreeSearch(Tree, Item);
int TreeHeight(Tree);
int TreeNumNodes(Tree);
Tree TreeInsert(Tree, Item);
Tree TreeDelete(Tree, Item);

Tree rotateRight(Tree);
Tree rotateLeft(Tree);
Tree insertAtRoot(Tree, Item);