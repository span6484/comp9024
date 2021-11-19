//
// Created by shao on 2021/11/18.
//
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int seed = atoi(argv[1]);
    int len = atoi(argv[2]);  //catch from terminal
    srand(seed); //seed the random
    int i = 0;
    char randLetter;
    for(i = 0; i < len; i++) {
        randLetter = 33 + rand() % (126-33);
        printf("%c",randLetter);
    }
    printf("\n");
    return 0;
}