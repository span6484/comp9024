//dynamic linklist
// Created by shao on 2021/9/26.
//

#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

typedef Node* LinkedNode;

int main(void){
    //定义结构体数组
    struct node list1[100];
    Node list2[100];
    //指针数组
    LinkedNode list3[100];
    //赋值
    list1[0].data = 100;
    list2[0].data = 100;
    list3[0]->data = 100; //指针
    //malloc 方式定义
    //malloc要保证定义的指针能够放入盖好的的房子空间里，不能小
    struct node *node1 = malloc(sizeof(struct node));
    struct node *node2 = malloc(sizeof(Node));

//    ******************************************************
    //错误案例
        //声明没问题， 但linkednode房子太小了，导致内存溢出
        //struct node 要比sizeof里面的小
//    struct node *node3 = malloc(sizeof(LinkedNode));
//    node3->data = 100;
//
//    node3->next = node1     //<- 这里错了，因为这里溢出了，内存太小

//    ********************************************************
    return 0;
}
