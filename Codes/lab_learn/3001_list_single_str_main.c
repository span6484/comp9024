//
// Created by shao on 2021/10/3.
//
#include <stdio.h>
#include "3000_1list_single_str.h"

int main(int argc, char *argv[]){
    LinkedStrNode header = NULL;
    char data[100];
    while (1){
        printf("Enter the vale here;");
        if(scanf("%s",data) == 1) {
            if(strcmp(data,"#") == 0){
                break;
            }
            header = insertListToHead(header,data);
        }
    }
    printf("Done\n");
    showStrList(header);
    freeStrList(header);
    return 0;
}