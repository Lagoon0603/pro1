#include <stdio.h>

int main( )
{
    int n;
    printf("正の整数nを入力してください：");
    scanf("%d", &n);

    int i;
    for (i = 1; i <= n; i++) {
        int j;
        for (j = 0; j < i; j++){
            printf("*");
        }
        printf("\n");
    }

    int k;
    for (k = n-1; k < n; k--) {
        int l;
        for (l = 0; l < k; l++){
            printf("*");
        }
        if(k == 1){
            continue;
        }else{
            printf("\n");
        }
        if(k == 0){
            break;
        }
    }
return 0;
}