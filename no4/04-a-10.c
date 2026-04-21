#include <stdio.h>
#include <stdlib.h>

void read_array(int *p, int n)
{
    int i;
    for(i = 0; i < n; i++){
        scanf("%d", p++);
    }
}

void print_array(int *p, int n)
{
    int i;
    for(i = 0; i < n; i++){
        printf("%d ", *p++);
    }
    printf("\n");
}

void dec_array(int *p, int n)
{
    int i;
    for(i = 0; i <n; i++){
        (*p)--;
        p++;
    }
}

int main()
{
    
    int a[5];
    int b[3];

    printf("input 5 integers: ");
    read_array(a, 5);

    printf("array a:\n");
    print_array(a, 5);
    dec_array(a, 5);
    print_array(a, 5);

    printf("\n");

    printf("input 3 integers: ");
    read_array(b, 3);

    printf("array b:\n");
    print_array(b, 3);
    dec_array(b, 3);
    print_array(b, 3);  
    return 0;
}