#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

#include "lib_graph.h"
#include "graph.h"

graph g_create(size_t size) {
    graph new = calloc(1, sizeof(struct Graph));
    assert(new);
    new->size = size;
    new->V = calloc(size, sizeof(struct Vertex));
    assert(new->V);

    for (size_t i = 0; i < size; i++) {
        new->V[i].exists = false;
        new->V[i].data = 0;
    }

    new->E = calloc(size, sizeof(struct Edge *));
    assert(new->E);

    for (size_t i = 0; i < size; i++) {
        new->E[i] = calloc(size, sizeof(struct Edge));
        assert(new->E[i]);
        for (size_t j = 0; j < size; j++) {
            new->E[i][j].exists = false;
            new->E[i][j].data = 0;
        }
    }

    return new;
}

void g_destroy(graph g) {
    assert(g);
    for (size_t i = 0; i < g->size; i++) free(g->E[i]);
    free(g->E);
    free(g->V);
    free(g);
}

void g_addVertex(graph g, size_t VertexID) {
    assert(g);
    assert(VertexID < g->size);
    g->V[VertexID].exists = true;
}


void g_removeVertex(graph g, size_t VertexID) {
    assert(g);
    assert(VertexID < g->size);
    g->V[VertexID].exists = false;
}

void g_setVertex(graph g, size_t VertexID, double value) {
    assert(g);
    assert(VertexID < g->size);
    g->V[VertexID].data = value;
}

double g_getVertex(graph g, size_t VertexID) {
    assert(g);
    assert(VertexID < g->size);
    return g->V[VertexID].data;
}

void g_addEdge(graph g, size_t VertexID1, size_t VertexID2) {
    assert(g);
    assert(VertexID1 < g->size);
    assert(VertexID2 < g->size);
    g->E[VertexID1][VertexID2].exists = true;
    g->E[VertexID2][VertexID1].exists = true;
}

void g_addEdge_di(graph g, size_t VertexID1, size_t VertexID2) {
    assert(g);
    assert(VertexID1 < g->size);
    assert(VertexID2 < g->size);
    g->E[VertexID1][VertexID2].exists = true;
}


void g_removeEdge(graph g, size_t VertexID1, size_t VertexID2) {
    assert(g);
    assert(VertexID1 < g->size);
    assert(VertexID2 < g->size);
    g->E[VertexID1][VertexID2].exists = false;
    g->E[VertexID2][VertexID1].exists = false;
}

void g_setEdge(graph g, size_t VertexID1, size_t VertexID2, double value) {
    assert(g);
    assert(VertexID1 < g->size);
    assert(VertexID2 < g->size);
    g->E[VertexID1][VertexID2].data = value;
    g->E[VertexID2][VertexID1].data = value;
}

double g_getEdge(graph g, size_t VertexID1, size_t VertexID2) {
    assert(g);
    assert(VertexID1 < g->size);
    assert(VertexID2 < g->size);
    return g->E[VertexID1][VertexID2].data;
}

void g_show(graph g) {
    assert(g);
    for (size_t i = 0; i < g->size; i++) {
        if (g->V[i].exists) {
            printf("%zu (%lf) |", i, g->V[i].data);
            for (size_t j = 0; j < g->size; j++) {
                if (g->V[j].exists && g->E[i][j].exists) {
                    printf(" %zu (%lf)", j, g->E[i][j].data);
                }
            }
            printf("\n");
        }
    }
}

void g_list(graph g) {
    printf("goto: https://csacademy.com/app/graph_editor/\n");
    printf("and enter the following data to view the graph.\n");
    assert(g);
    for (size_t i = 0; i < g->size; i++) {
        if (g->V[i].exists) printf("%zu\n", i);
    }
    for (size_t i = 0; i < g->size; i++) {
        if (g->V[i].exists) {
            for (size_t j = i; j < g->size; j++) {
                if (g->V[j].exists && g->E[i][j].exists) {
                    printf("%zu %zu\n", i, j);
                }
            }
        }
    }
}
