#include <stdio.h>

void print_seq(int n)
{
    if (n <= 0) {
        return;
    }
    print_seq(n - 1);
    printf("%d ", n);
}

int main(void)
{
    int n;
    printf("input a positive number: ");
    scanf("%d", &n);
    print_seq(n);
    printf("\n");
    return 0;
}