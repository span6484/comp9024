//
// Created by shao on 2021/10/8.
//

#include <stdio.h>
#include <string.h>

struct stu {
    char str[100];
    int a;
    float b;
} s1, s2;
int main(void) {
    char arr2[] = "123";
    char arr1[5] = "xxx\0p\0";

    printf("%d\n", sizeof(arr2) / sizeof(arr2[0]));
    return 0;
}
