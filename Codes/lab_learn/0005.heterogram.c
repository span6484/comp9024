//
// Created by shao on 2021/9/26.
//
#include <stdbool.h>
#include "stdio.h"
#include "string.h"
bool isHeterogram(char arr[100], int len);

int main()
{
    char arr[100];
    bool time;
    printf("Enter a word: ");
    scanf("%s",arr);
    int len = strlen(arr);
    time = isHeterogram(arr, len);
    if(time == true){
        printf("yes\n");
    }
    else{
        printf("no\n");

    }
    return 0;
}

bool isHeterogram(char arr[100], int len) {
    for(int i = 0; i < len; i++){
        for(int j = 0; j < len; j++){
            if (i != j) {
                if (arr[i] == arr[j]) {
                    return false;
                }
            }
        }
    }

    return true;
}
