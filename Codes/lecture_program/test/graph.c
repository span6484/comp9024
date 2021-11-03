//
// Created by shao on 2021/10/15.
//

#include "graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct GraphRep{
    int **matrix;
    int nV;         //number of vertices
    int nE;         //number of Edges
} GraphRep;



Graph newGraph(int n){
    assert(n>=0);
    int i;
    Graph g = malloc(sizeof(GraphRep));
    assert(g != NULL);
    g->nV = n;
    g->nE = 0;
    g->matrix = malloc(n * sizeof (Vertex *));
    for(i = 0; i < n; i++) {
        g->matrix[i] = calloc(n, sizeof(int));  //v*v matrix
        assert(g->matrix[i] != NULL);
    }

    return g;
}

void insertEdge(Graph g, Edges e){
    assert(g != NULL && e.x != e.y);
    if (g->matrix[e.x][e.y] == 0) {
        g->matrix[e.y][e.x] = 1;
        g->matrix[e.x][e.y] = 1;
        g->nE ++;
    }
}


void RemoveEdge(Graph g, Edges e){
    assert(g != NULL && e.x != e.y);
    if (g->matrix[e.x][e.y]) {
        g->matrix[e.y][e.x] = 0;
        g->matrix[e.x][e.y] = 0;
        g->nE --;
    }
}

void printGraph(Graph g){
    assert(g != NULL);
    int i, j;
    printf("numbers of vertices: %d\n", g->nV);
    printf("numbers of edges: %d\n", g->nE);
    for(i = 0; i < g->nV; i++){
        for(j = i+1; j < g->nV; j++){
            if(g->matrix[i][j]){
                printf("%d--%d\n", i, j);
            }
        }
    }
}

void freeGraph(Graph g){
    assert(g != NULL);
    int i;
    for(i=0; i < g->nV; i++){
        free(g->matrix[i]);
    }
    free(g->matrix);
    free(g);
}

















