//
// Created by shao on 2021/10/7.
//

#include <stdio.h>

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main(void){

    int arr[5] = {1,2,3,4};
    int *p = &arr;
    for(int i = 0; i < 4; i++){
        printf("%d ", *(p+i));
    }
    printf("\n");
    return 0;
}