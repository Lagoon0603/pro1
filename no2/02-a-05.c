#include <stdio.h>

int main( )
{
    int n;
    printf("非負整数nを入力してください\n");
    printf("input n:");
    scanf("%d", &n);

    int a = 0;
    int b = 1;
    int i, sum;
    
    if (n == 0){
        printf("fib(0) = %d\n", a);
    }else if(n == 1){
        printf("fib(1) = %d\n", b);
    }else{
        for(i = 2; i <= n; i++){
            sum = a + b;
            a = b;
            b = sum;
        }
        printf("fib(%d) = %d\n", n, b);
    }
    return 0;
}