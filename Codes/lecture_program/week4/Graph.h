//Graph ADT interface ... comp9024
// Created by shao on 2021/10/14.
//


#include <stdbool.h>

typedef struct GraphRep *Graph;
// vertices are int
typedef int Vertex;

// edges are pairs of vertices (end_point)

typedef struct Edge {
    Vertex x;
    Vertex y;
} Edge;

Graph newGraph (int);
int numOfVertices(Graph);
bool validV(Graph, Vertex);
bool adjacent(Graph g, Vertex, Vertex);
void insertEdge(Graph, Edge);
void removeEdge(Graph, Edge);
void showGraph(Graph);
void freeGraph(Graph g);


typedef struct GraphRepAL *GraphAL;
GraphAL newGraphAL(int);
void insertEdgeAL(GraphAL, Edge);
void showGraphAL(GraphAL g);
bool validVAL(GraphAL g, Vertex v);
void freeGraphAL(GraphAL g);
void removeEdgeAL(GraphAL g, Edge e);