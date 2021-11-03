//
// Created by shao on 2021/10/8.
//
#include <stdio.h>
#include "3004_wuziqiGame.h"
void menu();

void game();


int main() {
    int input = 0;
    do {
        menu();
        printf("choose: > ");
        scanf("%d", &input);
        switch (input) {
            case 1:
                printf("三子棋游戏\n");
                game();
                break;
            case 2:
                printf("退出游戏\n");
                break;
            default:
                printf("wrong input, choose again");
                break;
        }
    } while (input) ;
    return 0;
}

void game() {
    char board[ROW][COL];
    InitBoard(board, ROW, COL);
    DisplayBoard(board, ROW, COL);
}


void menu() {
    printf("************************\n");
    printf("****     1.play     ****\n");
    printf("****     0.exit     ****\n");
    printf("************************\n");
}
