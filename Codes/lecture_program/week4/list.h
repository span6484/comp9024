//
// Created by shao on 2021/10/15.
//
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
typedef struct Node *List;

struct Node *makeNode(int n);
bool inLL(List L, int n); //check does the val in the list

List insertLL(List L, int n);
void showLL(List L);
void freeLL(List L);
List deleteLL(List L, int n);