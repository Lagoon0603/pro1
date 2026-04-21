#include <stdio.h>
#include <stdlib.h>

int is_even(int n);
int is_odd(int n);

int main(void)
{
    int n;
    printf("input an integer: ");
    scanf("%d", &n);

    if (is_even(n)) {
        printf("%d is even\n", n);
    } else {
        printf("%d is odd\n", n);
    }

    return 0;
}

int is_even(int n)
{
    if (n == 0) {
        return 1;
    }
    return is_odd(abs(n) - 1);
}

int is_odd(int n)
{
    if (n == 0) {
        return 0;
    }
    return is_even(abs(n) - 1);
}