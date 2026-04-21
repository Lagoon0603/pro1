#include <stdio.h>

int gcd(int n1, int n2)
{
    if (n2 == 0) {
        return n1;
    }
    return gcd(n2, n1 % n2);
}

int main(void)
{
    int n1, n2;
    printf("input two positive numbers: ");
    scanf("%d %d", &n1, &n2);

    if (n1 <= 0 || n2 <= 0) {
        printf("must be positive\n");
    } else {
        printf("gcd(%d, %d) = %d\n", n1, n2, gcd(n1, n2));
    }

    return 0;
}