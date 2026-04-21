#include <stdio.h>

int memo[100];

int fib(int n)
{
    if (n == 0 || n == 1) {
        return 1;
    }
    if (memo[n] != 0) {
        return memo[n];
    }
    memo[n] = fib(n - 1) + fib(n - 2);
    return memo[n];
}

int main(void)
{
    int n, i;

    // 配列の初期化
    for (i = 0; i < 100; i++) {
        memo[i] = 0;
    }

    printf("input a non-negative number: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("must be non-negative\n");
    } else {
        printf("fib(%d) = %d\n", n, fib(n));
    }

    return 0;
}