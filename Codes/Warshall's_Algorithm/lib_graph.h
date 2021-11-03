#ifndef LIB_GRAPH_H
#define LIB_GRAPH_H

#include <stdbool.h>
#include <stddef.h>

typedef struct Vertex {
    bool   exists;
    double data;
} Vertex;

typedef Vertex *vertex;

typedef struct Edge {
    bool   exists;
    double data;
} Edge;

typedef Edge *edge;

typedef struct Graph {

    size_t  size;   //点数
    Vertex *V;      //一维数组存顶点
    Edge  **E;      //二维数组存边信息，表示为[点][点]
} Graph;

#endif // LIB_GRAPH_H