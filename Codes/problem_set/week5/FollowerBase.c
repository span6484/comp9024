#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "WGraph.h"

typedef struct Ranking {
    Vertex v;
    int in, out;
    float rank;
} Ranking;

// #edges into node, #edges out of a node

//

integer

        component

        =

#followers,

        fraction

                =

#following

/

#users

void insertionSort(Ranking array[], int n) {
    int i;

// sorting algorithm from week 1, adapted

    for (i = 1; i < n; i++) {

        Ranking element = array[i];

        int j = i - 1;

        while (j >= 0 && array[j].rank < element.rank) {

// for this element ...

            array[j + 1] = array[j];

            j--;

// ... work down the ordered list // ... moving elements up

        }

        array[j + 1] = element;

        void followerBase(Graph g) {

// and insert in correct position

        }

    }

    Vertex v, w;
    int nV = numOfVertices(g);

    Ranking *table = calloc(nV, sizeof(Ranking));

    for (v = 0; v < nV; v++) {

// initialise in = out = 0 // compute in and out degrees

        table[v].v = v;

        for (w = 0; w < nV; w++) {

            if (adjacent(g, v, w)) {
                table[v].out++;
                table[w].in++;
            }

        }

    }

    for (v = 0; v < nV; v++)

// determine ranking of all users

        table[v].rank = (float) table[v].in + (float) table[v].out / (float) nV;

    insertionSort(table, nV);
    printf("\nRanking by follower base:\n");

    for (v = 0; v < nV; v++)

// sort nodes by decreasing ranking

        printf("%d has %d follower(s) and follows %d user(s).\n", table[v].v, table[v].in, table[v].out);

    free(table);

}

int main(void) {

    Edge e = {0, 0, 1};

    int n;

// use constant edge weight = 1

    printf("Enter the number of users: ");
    scanf("%d", &n);
    Graph g = newGraph(n);

    printf("Enter a user (follower): ");
    while (scanf("%d", &e.v) == 1) {

        printf("Enter a user (followed by %d): ", e.v);

        scanf("%d", &e.w);

        insertEdge(g, e);

        printf("Enter a user (follower): ");
    }
    printf("Done.\n");

    followerBase(g);
    freeGraph(g);