#include <stdio.h>
#include <stdlib.h>

int a[6][5] = {{1, 1, 1, 1, 1}, {1, 1, 0, 1, 1}, {1, 0, 0, 0, 1}, {1, 1, 1, 0, 1}, {1, 0, 0, 0, 1}, {1, 1, 2, 1, 1}};

int x, y;

void hyouji(){
    for(int i = 1; i < 6; i++){
        for(int j = 0; j < 5; j++){
            if(i == y && j == x){
                printf("o ");
            }else if(a[i][j] == 0){
                printf(". ");
            }else if(a[i][j] == 1){
                printf("= ");
            }else if(a[i][j] == 2){
                printf("* ");
            }
        }
        printf("\n");
        }  
}

void move(){
    hyouji();

    if(a[y][x] == 2){
        printf("GOAL!\n");
        return;
    }

    int key;
    scanf("%d", &key);

    int nx = x;
    int ny = y;

    if(key == 8){
        ny = y - 1;
    }else if(key == 5){
        ny = y + 1;
    }else if(key == 4){
        nx = x - 1;
    }else if(key == 6){
        nx = x + 1;
    }

    if(a[ny][nx] != 1){
        x = nx;
        y = ny;
    }

    move();
}
int main(){

    x = 2;
    y = 1;

    move();

    return 0;
}