//
// Created by shao on 2021/10/15.
//

#include <stdlib.h>
#include <stdio.h>
typedef int Vertex;
//Edge 这个放在.h文件而不是.c 是因为main访问不到.c，.c是private文件，防止数组篡改;
typedef struct Edges{
    Vertex x;
    Vertex y;
}Edges;
//

typedef struct GraphRep *Graph;
Graph newGraph(int);
void insertEdge(Graph, Edges);
void RemoveEdge(Graph, Edges);
void printGraph(Graph);
void freeGraph(Graph);