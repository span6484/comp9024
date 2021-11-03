//
// Created by shao on 2021/9/21.
//

#ifndef C_ENV_SETTING_INTSTACK_H
#define C_ENV_SETTING_INTSTACK_H
#endif //C_ENV_SETTING_INTSTACK_H

// Integer Stack ADO header file ... COMP9024 21T3

#define MAXITEMS 10
#include "stdio.h"
#include "assert.h"
// set up empty stack
void StackInit();
int StackIsEmpty();
void StackPush(char ch);
char StackPop();
// insert int on top of stack // remove int from top of stack