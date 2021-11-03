//
// Created by shao on 2021/9/20.
//

#include <stdio.h>

#define MAX 10

void collatz(int n) {  // named after the German mathematician who invented this problem
    printf("%d\n", n);
    while (n != 1) {
        if (n % 2 == 0) {
            n = n / 2;
        } else {
            n = 3*n + 1;
        }
        printf("%d\n", n);
    }
}

int main(void) {
    int fib[MAX] = { 1, 1 };     // initialise the first two numbers
    int i;
    for (i = 2; i < MAX; i++) {  // compute the first 10 Fibonacci numbers
        fib[i] = fib[i-1] + fib[i-2];
    }

    for (i = 0; i < MAX; i++) {  // apply Collatz's process to each number
        printf("Fib[%d] = %d\n", i+1, fib[i]);
        collatz(fib[i]);
    }

    return 0;
}