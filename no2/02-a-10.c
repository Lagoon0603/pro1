#include <stdio.h>

int main( )
{
    int n;
    printf("60以上100未満の整数を入力してください\n");
    printf("input n(60 <= n < 100):");
    scanf("%d", &n);



    if(n == 60){
        printf("60\n");
    }else if(n == 80){
        printf("4 * 20\n");
    }else if(n < 80){
        printf("60 + %d\n", n - 60);
    }else{
        printf("4 * 20 + %d\n", n - 80);
    }
    return 0;
}