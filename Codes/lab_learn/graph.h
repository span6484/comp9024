#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef int Vertex;
typedef struct GraphRep *Graph;

typedef struct Edge {
    Vertex x;
    Vertex y
} Edge;

typedef struct GraphRep {
    int  **edges;   // adjacency matrix
    int num_v;
    int num_e;
} GraphRep;



Graph newGraph(int numNode);

void insertEdg(Graph graph, Edge edge);