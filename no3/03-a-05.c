#include <stdio.h>
#include <stdlib.h>

int a[5];

void input(){
    for(int i = 0; i <= 4; i++){
        printf("input a[%d]:", i);
        scanf("%d", &a[i]);
    }
}

void output(){
    for(int i = 0; i <= 4; i++){
        printf("%d ", a[4 - i]);
    }
    printf("\n");
}
int main(){
    printf("input 5 numbers...\n");

    input();
    output();

    return 0;
}