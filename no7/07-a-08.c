#include <stdio.h>

float power(int a, int n)
{
    float temp;
    if (n == 1) {
        return (float)a;
    }
    temp = power(a, n / 2);
    if (n % 2 == 0) {
        return temp * temp;
    } else {
        return a * temp * temp;
    }
}

int main(void)
{
    int a, n;
    printf("input two positive numbers: ");
    scanf("%d %d", &a, &n);

    if (a <= 0 || n <= 0) {
        printf("must be positive\n");
    } else {
        printf("%d^%d = %f\n", a, n, power(a, n));
    }

    return 0;
}
