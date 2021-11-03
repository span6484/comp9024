//
// Created by shao on 2021/9/24.
//


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void insert_sort(int arr[], int count);

int main()
{
    int arr[] = {7,1,3,2,5,4,6};
    int count = sizeof (arr) / sizeof (arr[0]);
    insert_sort(arr,count);
    for(int i = 0; i < count; i++)
    {
        printf("%d\n",arr[i]);
    }
    return 0;
}

void insert_sort(int arr[], int count) {
    int ele,j, temp;
    for (int i = 0; i < count; i++)
    {
        ele = arr[i];
        j = i - 1;
        temp = ele;

        while (j >= 0 && arr[j] > ele)
        {
            arr[j+1] = temp;
            arr[j+1] = arr[j];
            arr[j] = temp;
            j--;
        }

    }
}
