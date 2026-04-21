#include <stdio.h>
#include <stdlib.h>

int k;

int main(){
    
    int a[101];

    for (int i =0; i < 101; i++){
        a[i] = 1;
    }

    a[0] = 0;
    a[1] = 0;

    for (int p = 2; p < 101; p++){
        if(a[p] == 1){
            for(int j = p * 2; j <= 100; j = j + p){
                a[j] = 0;
            }
        }
    }

    for(k = 0; k < 101; k++){
        if(a[k] == 1){
            printf("%d ", k);
        }
    }
    printf("\n");
    return 0;
}