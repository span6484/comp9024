//
// Created by shao on 2021/9/20.
//

#include "stdio.h"

int main(void) {
    char arr[] = { 'a','c','d','g','o','t' };
    char temp_0;
    char temp_1;
    char temp_2;
    char temp_3;
    char temp_4;
    char temp_5;
    int count = 0;
    for (int i = 0; i < 6; i++) {
        temp_0 = arr[i];
        for (int j = 0; j < 6; j++) {
            temp_1 = arr[j];
            for (int k = 0; k < 6; k++) {
                temp_2 = arr[k];
                for (int l = 0; l < 6; l++) {
                    temp_3 = arr[l];
                    for (int a = 0; a < 6; a++) {
                        temp_4 = arr[a];

                        for (int b = 0; b < 6; b++) {
                            temp_5 = arr[b];
                            if (temp_0 != temp_1 && temp_0 != temp_2 && temp_0 != temp_3 && temp_0 != temp_4 &&
                                temp_0 != temp_5
                                && temp_1 != temp_2 && temp_1 != temp_3 && temp_1 != temp_4 && temp_1 != temp_5
                                && temp_2 != temp_3 && temp_2 != temp_4 && temp_2 != temp_5
                                && temp_3 != temp_4 && temp_3 != temp_5
                                && temp_4 != temp_5){
                                printf("%c%c%c%c%c%c\n", temp_0, temp_1, temp_2, temp_3, temp_4, temp_5);
                                count++;
                            }
                        }

                    }
                }
            }
        }

    }
    printf("%d\n", count);
    return 0;
}
