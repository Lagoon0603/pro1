#include <stdio.h>

int main( )
{
    float cm;
    printf("センチメートルを入力してください\n");
    printf("input cm:");
    scanf("%f", &cm);

    float in;
    in = cm / 2.54;
    printf("%.2fcm is %.2fin\n",cm, in);
    return 0;
}