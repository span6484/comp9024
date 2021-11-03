//There is a 5-digit number that satisfies 4·abcde = edcba,
// that is, when multiplied by 4 yields the same number read backwards. Write a C-program to find this number.
//
//Hint: Only use arithmetic operations; do not use any string operations.
# include <stdio.h>
#define MAX 99999
#define MIN 10000
int reverse(int num, int digit, int digit2);

int main (void)
{
    int digit = 10000;
    int digit2 = 1;
    int cmp_val = 0;
    int start = MAX;
    while (start >= MIN)
    {
        cmp_val = reverse(start,digit,digit2);
        if(cmp_val == (4 * start)){
            printf("i found!\n The val is %d\n", start);
            break;
        }
        start -= 1;
    }
    return 0;
}

int reverse(int num, int digit, int digit2) {
    int cmp_val = 0;
    int val;
    int temp;
    while(digit >= 1)
    {
        val = num / digit;
        temp = val;
        num -= val*digit;
        cmp_val += temp*digit2;
        digit /= 10;
        digit2 *= 10;
    }
    return cmp_val;
}
