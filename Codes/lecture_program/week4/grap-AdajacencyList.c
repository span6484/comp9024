//
// Created by shao on 2021/10/15.
//
#include "list.h"
#include "Graph.h"

typedef struct GraphRepAL {
    List *edges;        //array of lists
    int nV;
    int nE;
}GraphRepAL;

GraphAL newGraphAL(int nV){
    assert(nV >= 0);
    int i;
    GraphAL g = malloc(sizeof(GraphRepAL));
    assert(g != NULL);
    g->nV = nV;
    g->nE = 0;

    g->edges = malloc(nV * sizeof(List));
    assert(g->edges != NULL);
    for(i = 0; i < nV; i++)
        g->edges[i] = NULL;
    return g;
}
bool validVAL(GraphAL g, Vertex v) {
    return (g != NULL && v >= 0 && v < g->nV);
}
void insertEdgeAL(GraphAL g, Edge e) {
    assert(g != NULL && validVAL(g,e.x) && validVAL(g,e.y));

    if(!inLL(g->edges[e.x],e.y)) {
        g->edges[e.x] = insertLL(g->edges[e.x], e.y);
        g->edges[e.y] = insertLL(g->edges[e.y],e.x);
        g->nE++;
    }

}

void removeEdgeAL(GraphAL g, Edge e) {
    assert(g != NULL && validVAL(g,e.x) && validVAL(g,e.y));

    if(inLL(g->edges[e.x], e.y)) {
        g->edges[e.x] = deleteLL(g->edges[e.x],e.y);
        g->edges[e.y] = deleteLL(g->edges[e.y],e.x);
        g->nE--;
    }
}

void showGraphAL(GraphAL g) {
    assert(g != NULL);
    int i;

    printf("Number of vertices: %d\n", g->nV);
    printf("Number of edges: %d\n", g->nE);
    for (i = 0; i < g->nV; i++) {
        printf("%d - ", i);
        showLL(g->edges[i]);
    }
}


void freeGraphAL(GraphAL g) {
    assert(g != NULL);
    int i;

    for (i = 0; i < g->nV; i++)
        freeLL(g->edges[i]);

    free(g->edges);
    free(g);
}