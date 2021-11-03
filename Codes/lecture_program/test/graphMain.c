//
// Created by shao on 2021/10/15.
//
#include <stdio.h>
#include "graph.h"
#define NUM 5
int main(void){
    Graph g = newGraph(NUM);
    Edges e;
    e.x = 0;
    e.y = 1;
    insertEdge(g,e);
    e.x = 0;
    e.y = 2;
    insertEdge(g,e);
    e.x = 2;
    e.y = 3;
    insertEdge(g,e);
    RemoveEdge(g,e);
    printGraph(g);
    freeGraph(g);
    return 0;
}