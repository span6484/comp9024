//
// Created by shao on 2021/10/8.
//

#include <stdio.h>


void bubble_sort(int arr[], len);

int main(void) {
    int arr[] = {9,8,7,6,5,9,2,1};
    int len = sizeof(arr) / sizeof(arr[0]);
    bubble_sort(arr,len);
    for(int i = 0; i < len; i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}

void bubble_sort(int arr[], len) {
    for (int i = 0; i < len; i++) {
        int temp = 0;
        for (int j = 0; j < len -1 -i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }

}
