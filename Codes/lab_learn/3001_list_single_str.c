//
// Created by shao on 2021/10/3.
//

#include "3000_1list_single_str.h"

struct node{
    //不知道分配多长
    char *data;
    struct node *next;
};

struct list {
    LinkedStrNode first;
    LinkedStrNode last;

};

LinkedStrList createStrList(){
    LinkedStrList newList = malloc(sizeof(struct list));
    assert(newList != NULL);

    newList->first = NULL;
    newList->last = NULL;

    return newList;
}

void insertStrList(LinkedStrList linkedStrList, char data[]){
    LinkedStrNode newNode = makeNode(data);
    if (linkedStrList->first == NULL) {
        linkedStrList->first = linkedStrList->last = newNode;
    } else {
        linkedStrList->last->next = newNode;
        linkedStrList->last = newNode;
    }
}

//从最后删除
char * deleteStrFromLast(LinkedStrList linkedStrList){
    char *result = NULL;
    if(linkedStrList->first != NULL) {
        if(linkedStrList->first == linkedStrList->last) {
            result = linkedStrList->last->data;
            //不能直接free(linkedstrList->first->data)
            free(linkedStrList->last);
            linkedStrList->first = linkedStrList->last = NULL;

            //应该重新赋值
//            result = malloc(sizeof(char) * (strlen(linkedStrList->first->data) + 1));
//            strcpy(result, linkedStrList->first->data);
//            //因为已经copy，所以可以free
//            free(linkedStrList->first->data);
//            free(linkedStrList->first);
//            linkedStrList->first = linkedStrList->last = NULL;

        } else {
            LinkedStrNode cur = linkedStrList->first;
            while (cur->next != linkedStrList->last) {
                 cur = cur->next;
            }

            result = linkedStrList->last->data;
            free(linkedStrList->last);
            linkedStrList->last = cur;
        }
    }
    return result;
}
void showLinkedStrList(LinkedStrList linkedStrList) {
    if(linkedStrList->first != NULL) {
        showStrList(linkedStrList->first);
    }
}

void freeLinkedStrList(LinkedStrList linkedStrList){
    freeStrList(linkedStrList->first);
    free(linkedStrList);
}

//字符串肯定是指针
LinkedStrNode makeNode(char *data) {
    //heap 分配内存
    LinkedStrNode newNode = malloc(sizeof(struct node));

    //！！！！字符串操作不能直接用data
    //创建空间给data，不然如果free了，就会连同data一起free了
    newNode->data = malloc(sizeof(char) * (strlen(data)+1));
    assert(newNode->data != NULL);
    //把data val copy过来
    stpcpy(newNode->data, data);
    (newNode->data)[strlen(data)] = '\0';

    newNode->next = NULL;
    return newNode;
}

//insert
LinkedStrNode insertListToHead(LinkedStrNode header,char data[]){
    if(header == NULL){
        header = makeNode(data);
        return header;
    } else {
        LinkedStrNode newNode = makeNode(data);
        newNode->next = header;
        return newNode;
    }

}

// delete


//print list
void showStrList(LinkedStrNode header){
    if(header != NULL) {
        printf("%s",header->data);
        while(header->next != NULL) {
            printf("-->%s",header->next->data);
            header = header->next;
        }
        printf("\n");
    }
}

void freeStrList(LinkedStrNode header) {
    if(header != NULL){
         LinkedStrNode cur = header;
         LinkedStrNode next;
         while(cur != NULL) {
             next = cur->next;
             free(cur);
             cur = next;
         }
    }
}