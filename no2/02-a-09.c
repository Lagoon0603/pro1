#include <stdio.h>

int main( )
{
    float oz;
    printf("オンスを入力してください\n");
    printf("input (oz):");
    scanf("%f", &oz);

    float gm;
    float kg;
    gm = oz * 28.3;
    if(gm < 1000){
        printf("%foz is %fg\n", oz, gm);
    }else{
        kg = gm / 1000;
        printf("%foz is %fKg\n", oz, kg);
    }

    return 0;
}