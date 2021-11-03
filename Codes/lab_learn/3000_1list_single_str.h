 //
// Created by shao on 2021/10/3.
//
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include "string.h"
#include "assert.h"
typedef struct node *LinkedStrNode;

typedef struct list *LinkedStrList;

LinkedStrList createStrList();

void insertStrList(LinkedStrList linkedStrList, char data[]);

char * deleteStrFromLast(LinkedStrList linkedStrList);

void showLinkedStrList(LinkedStrList linkedStrList);

void freeLinkedStrList(LinkedStrList linkedStrList);

LinkedStrNode makeNode(char *data);
LinkedStrNode insertListToHead(LinkedStrNode header,char data[]);
void showStrList(LinkedStrNode header);
void freeStrList(LinkedStrNode header);
