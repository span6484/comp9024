//
// Created by shao on 2021/10/14.
//

#include <printf.h>
#include "Graph.h"
#define nV 5
int main(void){
    Graph g = newGraph(nV);
    Edge e;
    e.x = 1;
    e.y = 2;
    insertEdge(g,e);
    e.x = 2;
    e.y = 3;
    insertEdge(g,e);
    e.x = 4;
    e.y = 0;
    insertEdge(g,e);
    showGraph(g);
    freeGraph(g);
    return 0;
}