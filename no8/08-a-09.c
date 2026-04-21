#include <stdio.h>

int main(void) {
    char c;

    printf("Please help me! [y/n] ");
    c = getchar();

    switch (c) {
        case 'y':
        case 'Y':
            printf("Thank you!\n");
            break;
        case 'n':
        case 'N':
            printf("Huh?\n");
            break;
        default:
            printf("Yes or no!\n");
            break;
    }

    return 0;
}
