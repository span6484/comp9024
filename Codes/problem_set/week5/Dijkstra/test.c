// Test PQueue
// Created by shao on 2021/10/26.
//

#include <stdio.h>
#include "PQueue.h"


#define VERY_HIGH_VALUE 999999

int main(void) {
    int arr[4] = {5,2,6,7};
    PQueueInit();
    joinPQueue(0);

    joinPQueue(1);
    joinPQueue(2);
    joinPQueue(3);
    int b;

    while (!PQueueIsEmpty()){
        b = leavePQueue(arr);

        printf("%d\n", b);
    }
    return 0;
}