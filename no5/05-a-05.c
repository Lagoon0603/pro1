#include <stdio.h>
#include <math.h>

struct point {
    float x;
    float y;
};

void print_term(float coeff, char var_name, int* is_first_term) {

    if (coeff == 0) {
        return;
    }

    if (!(*is_first_term)) {
        if (coeff > 0) {
            printf("+");
        }
    }

    *is_first_term = 0; 

    if (coeff == 1 && var_name != '\0') {
        printf("%c", var_name);
    } else if (coeff == -1 && var_name != '\0') {
        printf("-%c", var_name);
    } else if (var_name != '\0') {
        printf("%f%c", coeff, var_name);
    } else { // 定数項の場合
        printf("%f", coeff);
    }
}


int main() {

    struct point p1, p2;

    printf("input p1.x p1.y: ");
    scanf("%f %f", &p1.x, &p1.y);

    printf("input p2.x p2.y: ");
    scanf("%f %f", &p2.x, &p2.y);

    if (p1.x == p2.x && p1.y == p2.y) {
        printf("the same point...\n");
        return 1;
    }

    float a = p1.y - p2.y;
    float b = p2.x - p1.x;
    float c = p1.x * p2.y - p2.x * p1.y;

    if (a != 0) {
        b /= a;
        c /= a;
        a = 1;
    } else if (b != 0) { 
        c /= b;
        b = 1;
    }
    
    int is_first = 1;

    print_term(a, 'x', &is_first);
    print_term(b, 'y', &is_first);
    print_term(c, '\0', &is_first);

    printf("=0\n");

    return 0;
}