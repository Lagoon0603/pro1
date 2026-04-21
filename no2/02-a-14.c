#include <stdio.h>

int main( )
{
    int year;
    printf("input year:");
    scanf("%d", &year);

    int month;
    printf("input month:");
    scanf("%d", &month);

    int day;
    printf("input day:");
    scanf("%d", &day);

    int h;
    h = (year + (year / 4) - (year / 100) + (year / 400) + ((13 * month + 8) / 5) + day) % 7;
    printf("h = %d\n", h);

    return 0;
}