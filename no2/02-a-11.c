#include <stdio.h>

int main( )
{
    int H1;
    printf("input H1(earlier):");
    scanf("%d", &H1);
    int M1;
    printf("input M1(earlier):");
    scanf("%d", &M1);

    int H2;
    printf("input H2(later):");
    scanf("%d", &H2);
    int M2;
    printf("input M2(later):");
    scanf("%d", &M2);



    int h_dif;
    int m_dif;
    if(M1 < M2){
       h_dif = H2 - H1;
       m_dif = M2 - M1;
       printf("%02d:%02d\n", h_dif, m_dif);
    }else{
        h_dif = H2 - H1 - 1;
        m_dif = M2 - M1 + 60;
        printf("%02d:%02d\n", h_dif, m_dif);
    }
    return 0;
}