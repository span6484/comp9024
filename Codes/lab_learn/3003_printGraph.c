//
// Created by shao on 2021/10/8.
//

#include <stdio.h>

//打印菱形
int main(void) {

    int line;
    printf("Enter the line you wanna print a rhombus: ");
    scanf("%d", &line);
    int space = 0;
    int star = 0;

    for(int no = 1; no < line+1; no++) {
        space = line - no;
        star = line - space - 1;

        for(int i = 0; i < space; i++) {
            printf(" ");
        }
        for(int j = 0; j < star; j++) {
            printf("*");
        }
        printf("*");
        for(int j = 0; j < star; j++) {
            printf("*");
        }
        printf("\n");

    }

    for(int no = line - 1; no > 0; no--) {
        space = line - no;
        star = line - space - 1;

        for(int i = 0; i < space; i++) {
            printf(" ");
        }
        for(int j = 0; j < star; j++) {
            printf("*");
        }
        printf("*");
        for(int j = 0; j < star; j++) {
            printf("*");
        }
        printf("\n");

    }
    return 0;
}