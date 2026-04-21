#include <stdio.h>
#include <stdlib.h>

int scanf_int(int *p)
{
    if(scanf("%d", p) != 1) {
        printf("incorrect input\n");
        exit(1);
    }
    return *p;
}

float scanf_float(float *p)
{
    if(scanf("%f", p) != 1) {
        printf("incorrect input\n");
        exit(1);
    }
    return *p;
}


int main()
{
    int x;
    float y;

    printf("input int: ");
    scanf_int(&x);
    printf("read: %d\n", x);

    printf("input float: ");
    scanf_float(&y);
    printf("read: %f\n", y);

    return 0;
}