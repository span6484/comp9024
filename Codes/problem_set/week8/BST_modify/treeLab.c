//
// Created by shao on 2021/11/7.
//

// Binary Search Tree ADT Tester ... COMP9024 21T3

#include <stdlib.h>
#include <stdio.h>
#include "BST.h"

#define MAX_STR_LEN 20

void help();

int main(void) {
    Tree mytree = newTree();

    bool noShow = false;
    char line[MAX_STR_LEN];
    printf("\n> ");
    while (fgets(line,MAX_STR_LEN,stdin) != NULL) {
        int value = atoi(&line[1]);
        switch (line[0]) {

            case 'n':
                freeTree(mytree);
                mytree = newTree();
                break;

            case 'i':
                mytree = TreeInsert(mytree, value);
                break;

            case 'I':
                mytree = insertAtRoot(mytree, value);
                break;

            case 'R':
                mytree = insertRandom(mytree, value);
                break;

            case 'a':
                mytree = insertAVL(mytree, value);
                break;

            case 'z':
                mytree = insertSplay(mytree, value);
                break;

            case 'd':
                mytree = TreeDelete(mytree, value);
                break;

            case 's':
                if (TreeSearch(mytree, value))
                    printf("Found!\n");
                else
                    printf("Not found\n");
                noShow = true;
                break;

            case 'r':
                mytree = rotateRight(mytree);
                break;

            case 'l':
                mytree = rotateLeft(mytree);
                break;

            case 'b':
                mytree = rebalance(mytree);
                break;

            case 'q':
                printf("Bye.\n");
                freeTree(mytree);
                return 0;

            default:
                help();
                noShow = true;
        }

        if (noShow) {
            noShow = false;
            printf("\n> ");
        } else {
            printf("New Tree:");
            printf("  #nodes = %d,  ", TreeNumNodes(mytree));
            printf("  height = %d\n", TreeHeight(mytree));
            if (TreeHeight(mytree) < 8)
                showTree(mytree);
            else
                printf("New Tree is too deep to display nicely\n");
            printf("\n> ");
        }
    }

    freeTree(mytree);
    return 0;
}

void help() {
    printf("Commands:\n");
    printf("n = make a new tree\n");
    printf("i N = insert N into tree\n");
    printf("I N = insert N into tree at root\n");
    printf("R N = insert N at random\n");
    printf("a N = insert N into AVL tree\n");
    printf("z N = insert N into Splay tree\n");
    printf("d N = delete N from tree\n");
    printf("s N = search for N in tree\n");
    printf("r = rotate tree right around root\n");
    printf("l = rotate tree left around root\n");
    printf("b = rebalance tree\n");
    printf("q = quit\n");
}