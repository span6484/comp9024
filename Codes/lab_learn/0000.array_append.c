//
// Created by shao on 2021/9/24.
//


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int *append(int *array, int data, int *array_size, int *array_elements_count);

int main()
{

    int *array = NULL;
    int array_size = 2;
    int array_elements_count = 0;
    array = append(array, 1, &array_size, &array_elements_count);
    array = append(array, 5, &array_size, &array_elements_count);
    array = append(array, 8, &array_size, &array_elements_count);

    printf("arraycoutn is %d\n",array_elements_count);
    for(int i = 0; i < array_elements_count; i++)
    {
        printf("the index of %d value is %d\n", i, array[i]);
    }
    return 0;
}

int *append(int *array, int data, int *array_size, int *array_elements_count)
{
    //分配内存
    if (array == NULL)
    {
        array = malloc(sizeof(int) * (*array_size));
    }

    //如果相等
    if (*array_size == *array_elements_count)
    {
        *array_size = *array_size * 2;
        //扩大内存
        array = realloc(array, sizeof(int) * (*array_size));
    }
    //数组添加一个元素
    array[*array_elements_count] = data;
    (*array_elements_count)++;
    return array;
}
