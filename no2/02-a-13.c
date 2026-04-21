#include <stdio.h>

int main( )
{
    int era;
    printf("input era name (0 Meiji, 1 Taisho, 2 Showa, 3 Heisei, 4 Reiwa):");
    scanf("%d", &era);

    int year;
    printf("input year:");
    scanf("%d", &year);

    int seireki;
    if(era == 0){
        if(year > 45){
            printf("Incorrect year. Meiji is from 1 to 45\n");
        }else{
            seireki = 1868 + year - 1;
            printf("Meiji %d is %d\n", year, seireki);
        }
    }else if(era == 1){
        if(year > 15){
            printf("Incorrect year. Taisho is from 1 to 15\n");
        }else{
            seireki = 1912 + year - 1;
            printf("Taisho %d is %d\n", year, seireki);
        }
    }else if(era == 2){
        if(year > 15){
            printf("Incorrect year. Showa is from 1 to 64\n");
        }else{
            seireki = 1926 + year - 1;
            printf("Showa %d is %d\n", year, seireki);
        }
    }else if(era == 3){
        if(year > 64){
            printf("Incorrect year. Heisei is from 1 to 31\n");
        }else{
            seireki = 1989 + year - 1;
            printf("Heisei %d is %d\n", year, seireki);
        }
    }else if(era == 4){
        seireki = 2019 + year - 1;
        printf("Reiwa %d is %d\n", year, seireki);
    }else if(era > 4){
        printf("Era must be 0, 1, 2, 3, 4\n");
    }
    return 0;
}