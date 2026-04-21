#include <stdio.h>

int main( )
{
    printf("aの値を入力してください：");
    int a;
    scanf("%d", &a);

    printf("bの値を入力してください：");
    int b;
    scanf("%d", &b);

    printf("input a: %d\n", a);
    printf("input b: %d\n", b);
    printf("a + b = %d\n", a + b);
    printf("a - b = %d\n", a - b);
    printf("a * b = %d\n", a * b);
    printf("a / b = %d\n", a / b);
    printf("a / b = %f\n", (float)a / b);
    printf("a %% b = %d\n", a % b);
return 0;
}