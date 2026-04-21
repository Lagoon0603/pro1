#include <stdio.h>
#include <stdlib.h>

int a[100];
int n, sum, min, max;
float ave;

int main(){

    printf("input #(1-100) of numbers:");
    scanf("%d", &n);

    if(n > 100 || n < 1){
        printf("n(%d) should be 1...100\n", n);
        exit(1);
    }else{
        for(int i = 0; i < n; i++){
            printf("input a[%d]:", i);
            scanf("%d", &a[i]);
        }

        min = a[0];
        max = a[0];
        sum = 0;

        for(int i = 0; i < n; i++){ 
            if(min > a[i]){
                min = a[i];
            }

            if(max < a[i]){
                max = a[i];
            }

            sum = sum + a[i];
        }

        ave = (float)sum / n;

        for(int i = 0; i < n; i++){
        printf("a[%d] = %d\n", i, a[i]);
        }

        printf("min = %d, max = %d, ave = %f\n",min, max, ave);

    }
    return 0;
}