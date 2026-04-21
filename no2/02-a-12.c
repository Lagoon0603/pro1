#include <stdio.h>

int main( )
{
    int year;
    printf("input year:");
    scanf("%d", &year);


    int seireki;
    int y_dif;
    if(year < 1868){
       printf("year must be greater than or equal to 1868\n");
    }else if(year >= 1868 && year < 1912){
        y_dif = year - 1868 + 1;
        printf("Meiji %d\n", y_dif);
    }else if(year > 1912 && year < 1926){
        y_dif = year - 1912 + 1;
        printf("Taisho %d\n", y_dif);
    }else if(year > 1926 && year < 1989){
        y_dif = year - 1926 + 1;
        printf("Showa %d\n", y_dif);
    }else if(year > 1989 && year < 2019){
        y_dif = year - 1989 + 1;
        printf("Heisei %d\n", y_dif);
    }else if(2019 < year){
        y_dif = year - 2019 + 1;
        printf("Reiwa %d\n", y_dif);
    }else if(year == 1912){
        printf("Meiji 45, Taisho 1\n");
    }else if(year == 1926){
        printf("Taihsho 15, Showa 1\n");
    }else if(year == 1989){
        printf("Showa 64, Heisei 1\n");
    }else if(year == 2019){
        printf("Heisei 31, Reiwa 1\n");
    }
    return 0;
}