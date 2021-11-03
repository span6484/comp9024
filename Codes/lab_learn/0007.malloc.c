//
// Created by shao on 2021/10/3.
//

#include <assert.h>
#include <stdlib.h>

typedef struct {
    int day, month;
} DateT;

typedef struct {

    int hour, minute;
} TimeT;

typedef struct {
    char plate[7]; double speed;
    DateT d; TimeT t;
} TicketT;

int main(void){
    TicketT *tickets;
    tickets = malloc(1000 * sizeof(TicketT));
    assert(tickets != NULL);
    return 0;
}