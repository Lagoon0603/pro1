#include <stdio.h>

int main( )
{
    int a;
    printf("整数aを入力してください\n");
    printf("input a:");
    scanf("%d", &a);

    int b;
    printf("整数bを入力してください\n");
    printf("input b:");
    scanf("%d", &b);

    if(a < b){
        printf("%d is greater than %d.\n", b, a);
    }else if(a > b){
        printf("%d is greater than %d.\n", a, b);
    }else{
        printf("%d equals %d.\n", a, b);
    }
}