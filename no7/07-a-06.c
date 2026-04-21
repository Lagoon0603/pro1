#include <stdio.h>

int ackermann(int m, int n)
{
    if (m == 0) {
        return n + 1;
    } else if (n == 0) {
        return ackermann(m - 1, 1);
    } else {
        return ackermann(m - 1, ackermann(m, n - 1));
    }
}

int main(void)
{
    int m, n;
    printf("input two non-negative numbers: ");
    scanf("%d %d", &m, &n);

    if (m < 0 || n < 0) {
        printf("must be non-negative\n");
    } else {
        printf("ackermann(%d, %d) = %d\n", m, n, ackermann(m, n));
    }

    return 0;
}