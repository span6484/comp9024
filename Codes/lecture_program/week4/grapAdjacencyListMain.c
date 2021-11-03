//
// Created by shao on 2021/10/15.
//


#include <stdio.h>
#include "list.h"
#include "Graph.h"

int main(void) {
    GraphAL g = newGraphAL(5);
    Edge e;
    e.x = 1;
    e.y = 2;
    insertEdgeAL(g,e);
    e.x = 1;
    e.y = 3;
    insertEdgeAL(g,e);
    e.x = 3;
    e.y = 4;
    insertEdgeAL(g,e);
    e.x = 1;
    e.y = 4;
    insertEdgeAL(g,e);
    showGraphAL(g);

    removeEdgeAL(g,e);
    printf("\n");
    showGraphAL(g);
    freeGraphAL(g);
    return 0;
}

