#include <stdio.h>
#include <math.h>

struct mydate{
    int year;
    int month;
    int date;
};

void printdate(struct mydate p)
{
    printf("%04d/%02d/%02d\n", p.year, p.month, p.date);
}

int main()
{
    struct mydate m;
    printf("input year month date:");
    scanf("%d %d %d", &m.year, &m.month, &m.date);
    printdate(m);
    return 0;
}
