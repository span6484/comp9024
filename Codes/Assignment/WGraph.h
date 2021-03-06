//
// Created by shao on 2021/11/2.
//

// Weighted Graph ADT interface ... COMP9024 21T3

typedef struct GraphRep *Graph;

// vertices are ints
typedef int Vertex;

// edges are pairs of vertices (end-points) with a weight
typedef struct Edge {
    Vertex v;
    Vertex w;
    int    weight;
} Edge;

Graph newGraph(int);
int   numOfVertices(Graph);
void  insertEdge(Graph, Edge);
void  removeEdge(Graph, Edge);
int   adjacent(Graph, Vertex, Vertex);  // returns weight, or 0 if not adjacent
void  showGraph(Graph);
void  freeGraph(Graph);

void displayPath(Graph pRep, char pString[][32], int vertex); // print words one by one  east: eat fast