//
// Created by shao on 2021/10/12.
//

#include "graph.h"

Graph newGraph(int numVertex) {
    Graph g = malloc(sizeof(GraphRep));
    assert(g != 0);
    g->num_v = numVertex;
    g->num_e = 0;
    g->edges = malloc(numVertex *(sizeof (int *)));
    assert(g->edges != NULL);
    for(int i = 0; i < numVertex; i++) {
        g->edges[i] = calloc(numVertex, sizeof (int));
        assert(g->edges[i] != NULL);
    }
    return g;
}

void insertEdg(Graph g, Edge e) {
    if (!g->edges[e.x][e.y]) {  // edge e not in graph
        g->edges[e.x][e.y] = 1;
        g->edges[e.y][e.x] = 1;
        g->num_e += 1;
    }
}