#include <stdio.h>

int main( )
{
    float oz;
    printf("オンスを入力してください\n");
    printf("input (oz):");
    scanf("%f", &oz);

    float gm;
    gm = oz * 28.3;
    printf("%foz is %fg\n", oz, gm);
    return 0;
}