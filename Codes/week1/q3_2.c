//
// Created by shao on 2021/9/20.
//

#include "q3_2.h"
#include "stdio.h"
int Fib(int a);

int main(void)
{
    int a;
    int val;
    for(int i = 1; i < 10; i ++)
    {
        val = Fib(i);
        printf("the val is %d\n", val);
    }
    return 0;
}

int Fib(int val) {
    if(val == 1 || val == 2)
    {
        val = 1;
        return val;
    }
    return Fib(val - 1) + Fib(val-2);
}
