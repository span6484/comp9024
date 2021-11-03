//
// Created by shao on 2021/9/30.
//
#include <stdio.h>
#include <stdlib.h>

int main(void){
    int *p;
    int x = 100;
    p = &x;
    printf("%d, \n", *p);
    //**************
//这两个分配内存是一样的,a,b
//    int a[100];
//    int *b = malloc(sizeof(int) * 100);
    //************
    p = malloc(sizeof(int) * 100);
    printf("%p, %p, %d, %d\n",p, &p[0], *p, p[0]);
    free(p);
}

