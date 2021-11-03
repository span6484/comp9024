#include <stdlib.h>  // for `malloc()` and `realloc()`
#include <stdio.h>   // for `printf()` and `getline()` and `fileno()`
#include <stdbool.h> // for `bool`
#include <stddef.h>  // for `size_t`
#include <unistd.h>  // for `isatty()`
#include <string.h>  // for `strtok()` and `strcasecmp()` and `strlen()`
#include <ctype.h>   // for `isupper()` and `islower()` and `isdigit()`

#include "graph.h"
#include "lib_graph.h"


bool g_is_transitive(graph g) {
    for (int i = 0; i < g->size; i++) {
        for (int j = 0; j < g->size; j++) {
            for (int q = 0; q < g->size; q++) {
                if (g->E[j][i].exists && g->E[i][q].exists && g->E[j][q].exists) { continue; }
                else if (g->E[j][i].exists && g->E[i][q].exists && g->E[j][q].exists == false) { return false; }
            }
        }
    }
    return true;
}

void Warshall(graph g) {
    int count = 0;
    for (int i = 0; i < g->size; i++) {
        if (g_is_transitive(g) == true) { break; }
        printf("第%d次处理了：\n", count + 1);
        for (int s = 0; s < g->size; s++) {
            for (int t = 0; t < g->size; t++) {
                if (g->E[s][i].exists && g->E[i][t].exists) {
                    count = i + 1;
                    g_addEdge(g, s, t);
                    printf("V%d--V%d & V%d--V%d  →  V%d和V%d\n", s, i, i, t, s, t);
                }
            }
        }
        printf("第%d次iteration：\n", count);
        for (int q = 0; q < g->size; q++) {
            for (int j = 0; j < g->size; j++) {
                printf("%d ", g->E[i][j].exists);
            }
            printf("\n");
        }
    }
    printf("总循环次数：%d\n", count);
}


int main(void) {
    // 构建一个图，参数为vertex个数（如 "6"）
    graph g = g_create(6);
    for (int i = 0; i < g->size; i++) { g_addVertex(g, i); }
    // g_addEdge方法为添加无向边
    g_addEdge(g, 0, 0);
    g_addEdge(g, 0, 3);
    g_addEdge(g, 0, 4);
    g_addEdge(g, 1, 1);
    g_addEdge(g, 1, 2);
    g_addEdge(g, 1, 3);
    g_addEdge(g, 2, 1);
    g_addEdge(g, 2, 2);
    g_addEdge(g, 3, 0);
    g_addEdge(g, 3, 1);
    g_addEdge(g, 3, 3);
    g_addEdge(g, 3, 5);
    g_addEdge(g, 4, 4);
    g_addEdge(g, 5, 3);
    g_addEdge(g, 5, 5);
    printf("原始图：\n");
    for (int i = 0; i < g->size; i++) {
        for (int j = 0; j < g->size; j++) {
            printf("%d ", g->E[i][j].exists);
        }
        printf("\n");
    }
    Warshall(g);
    return 0;
}