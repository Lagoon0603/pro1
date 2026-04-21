#include <stdio.h>
#include <stdlib.h>

int pre_inc(int *p)
{
    *p += 1;
    return *p;
}

int post_inc(int *p)
{
    int q = *p;
    *p += 1;
    return q;
}

int main()
{
    int x = 10, y;

    y = pre_inc(&x);
    if (x == 11 && y == 11)
        printf("O\n");
    else
        printf("X\n");

    y = post_inc(&x);
    if (x == 12 && y == 11)
        printf("O\n");
    else
        printf("X\n");

    return 0;
}
