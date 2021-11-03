//
// Created by shao on 2021/10/12.
//

#include "graph.h"
#define numVertex 5


void showGraph(Graph g);

int main(void) {
    Edge e;
    Graph g =  newGraph(numVertex);
    e.x = 0; e.y = 4;
    insertEdg(g,e);
    e.x = 1; e.y = 3;
    insertEdg(g,e);
    e.x =4; e.y = 2;
    insertEdg(g,e);
    showGraph(g);
    return 0;
}

void showGraph(Graph g) {
    assert(g != NULL);
    int i, j;

    printf("Number of vertices: %d\n", g->num_v);
    printf("Number of edges: %d\n", g->num_e);
    for (i = 0; i < g->num_v; i++)
        for (j = i+1; j < g->num_v; j++)
            if (g->edges[i][j] == 1)
                printf("Edge %d - %d\n", i, j);
}

