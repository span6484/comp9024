// Starting code for Dijkstra's algorithm ... COMP9024 21T3

#include <stdio.h>
#include <stdbool.h>
#include "PQueue.h"

#define VERY_HIGH_VALUE 999999

void showPath(int s, int pred[]);

void dijkstraSSSP(Graph g, Vertex source) {
    int  dist[MAX_NODES];
    int  pred[MAX_NODES];
    bool vSet[MAX_NODES];  // vSet[v] = true <=> v has not been processed
    int s, t, cur,path;

    PQueueInit();
    int nV = numOfVertices(g);
    for (s = 0; s < nV; s++) {
        joinPQueue(s);
        dist[s] = VERY_HIGH_VALUE;
        pred[s] = -1;
        vSet[s] = true;
    }
    dist[source] = 0;
//    ==================================================
//    ==================================================
    /* NEEDS TO BE COMPLETED */
    while(!PQueueIsEmpty()){
        cur = leavePQueue(dist);
        vSet[cur] = false;
        printf("%d ", cur);
        for(int i = 0; i < nV; i++){
            path = adjacent(g, cur, i);
            if (path>0 && path + dist[cur] < dist[i] && vSet[i] == true) {
                dist[i] = path + dist[cur];
                pred[i] = cur;
            }
        }
    }
    printf("\n");
    for (s = 0; s < nV; s++) {
        printf("%d: ", s);
        if (dist[s] < VERY_HIGH_VALUE) {
        printf("distance = %d, shortest path: ", dist[s]);
        showPath(s, pred);
        putchar('\n');
        }
        else {
            printf("no path\n");
        }
    }
}

void showPath(int s, int pred[]) {
    if(pred[s] == -1) {
        printf("%d",s);
    }
    else{
        showPath(pred[s], pred);
        printf("-%d",s);
    }
}
//    ==================================================
//    ==================================================
void reverseEdge(Edge *e) {
    Vertex temp = e->v;
    e->v = e->w;
    e->w = temp;
}

int main(void) {
    freopen("/Users/shao/Documents/unsw/2021-s3/comp9024/C_ENV_SETTING-master/Codes/problem_set/week5/test.txt", "r",
            stdin);
    Edge e;
    int  n, source;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    Graph g = newGraph(n);

    printf("Enter the source node: ");
    scanf("%d", &source);
    printf("Enter an edge (from): ");
    while (scanf("%d", &e.v) == 1) {
        printf("Enter an edge (to): ");
        scanf("%d", &e.w);
        printf("Enter the weight: ");
        scanf("%d", &e.weight);
        insertEdge(g, e);
        reverseEdge(&e);               // ensure to add edge in both directions
        insertEdge(g, e);
        printf("Enter an edge (from): ");
    }
    printf("Done.\n");

    dijkstraSSSP(g, source);
    freeGraph(g);
    return 0;
}