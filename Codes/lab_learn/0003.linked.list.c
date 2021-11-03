//静态链表
// Created by shao on 2021/9/25.
//https://www.bilibili.com/video/BV1yv411y7AW?p=2

#include "stdio.h"
#include "stdlib.h"
struct node {
    int value;
    struct node *next;
};

void test()
{
    struct node node1 = {10,NULL};
    struct node node2 = {20,NULL};
    struct node node3 = {30,NULL};
    struct node node4 = {40,NULL};
    struct node *cur = &node1;
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    while(cur != NULL)
    {
        printf("%d->", cur->value);
        cur = cur->next;
    }
    printf("NULL\n");
}

int main()
{
    test();
    return 0;
}