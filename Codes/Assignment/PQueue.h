//
// Created by shao on 2021/11/3.
//

// Priority Queue ADO header ... COMP9024 21T3

#include "WGraph.h"
#include <stdbool.h>

#define MAX_NODES 1000

void   PQueueInit();
void   joinPQueue(Vertex);
Vertex popPQueue(int[]);
bool   PQueueIsEmpty();