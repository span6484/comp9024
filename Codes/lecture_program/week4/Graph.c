//
// Created by shao on 2021/10/14.
//

#include "Graph.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef struct GraphRep {
    int **edges;            //adjacency matrix
    int nV;                 // #vertices
    int nE;                 // #Edges
}GraphRep;

Graph newGraph(int v) {
    assert(v >= 0);
    int i;
    Graph g = malloc(sizeof (GraphRep));
    g->nE = 0;
    g->nV = v;
    // allocate row for each row
    g->edges = malloc(v * sizeof (int*));
    assert(g->edges != NULL);
    for(int i = 0; i < v; i++) {
        g->edges[i] = calloc(v, sizeof(int));
        assert(g->edges[i] != NULL);
    }
    return g;
}

int numOfVertices(Graph g){
    return g->nV;
}

bool validV(Graph g, Vertex v){
    return (g != NULL && v >= 0 && v < g->nV);
}

void insertEdge(Graph g, Edge e){
    assert(g != NULL && validV(g,e.x) && validV(g,e.y));

    if(!g->edges[e.x][e.y]){
        g->edges[e.x][e.y] = 1;
        g->edges[e.y][e.x] = 1;
        g->nE++;
    }

}

void removeEdge(Graph g, Edge e){
    assert(g != NULL && validV(g,e.x) && validV(g,e.y));

    if(g->edges[e.x][e.y]) {
        g->edges[e.x][e.y] = 0;
        g->edges[e.y][e.x] = 0;
        g->nE--;
    }
}

//check two points connected to each other
bool adjacent(Graph g, Vertex x, Vertex y){
    assert(g != NULL && validV(g,x) && validV(g,y));
    return (g->edges[x][y] != 0);
}

void showGraph(Graph g){
    assert(g != NULL);
    int i, j;
    printf("numbers of vertices: %d\n", g->nV);
    printf("numbers of edges: %d\n", g->nE);
    for(i = 0; i < g->nV; i++) {
        for(j = i+1; j < g->nV; j++) {
            if (g->edges[i][j])
                printf("Edge %d - %d\n", i, j);
        }
    }
}

void freeGraph(Graph g) {
    assert(g != NULL);
    int i;
    for(i = 0; i < g->nV; i++)
        free(g->edges[i]);
    free(g->edges);
    free(g);
}