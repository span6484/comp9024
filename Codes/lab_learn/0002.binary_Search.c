//
// Created by shao on 2021/9/25.
//

#include "stdio.h"
#include "string.h"

int search(int v, int arr[], int lo, int hi);

int main()
{
    int val,index,lo,hi,sit;
    int arr[] = {1,2,3,4,5,6,7,8};
    lo = 0;
    hi = sizeof arr / sizeof(int) - 1;

    sit = 0;
    while(sit == 0)
    {
        printf("Please Enter the val u wanna search:\n");
        scanf("%d", &val);
        index = search(val,arr,lo,hi);
        if(index == -1)
        {
            printf("There's no val in this array\n");
        }
        else
        {
            printf("The index of %d is %d\n", val, index);
        }
    }
    return 0;
}

int search(int v, int arr[], int lo, int hi) {
    int mid;
    mid = (lo+hi) / 2;
//    printf("mid is %d\n", mid);
//    printf("%d\n",arr[mid]);
//    printf("%d\n",v);
    if(lo > hi)
    {
        return -1;
    }

    if(arr[mid] == v)
    {
        printf("we found it!\n");
        return mid;
    }

    else if(arr[mid] < v)
    {
        return search(v,arr, mid+1,hi);
    }
    else
    {
        return search(v,arr,lo, mid-1);
    }
}
