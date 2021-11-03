//
// Created by shao on 2021/9/20.
//

#include "stdio.h"

int main(void)
{
    int a;
    printf("Please enter the integer: \n");
    scanf("%d",&a);
    if(a % 2 == 0)
    {
        a = a / 2;
    }
    else
    {
        a = 3 * a + 1;
    }
    printf("The a is %d\n", a);
}
