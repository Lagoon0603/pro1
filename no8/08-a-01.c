#include <stdio.h>

void print_ascii(char *str) {
    while (1) {
        printf("%d ", *str);
        if (*str == '\0') {
            break;
        }
        str++;
    }
    printf("\n");
}

int main(void) {
    char str[4];

    printf("input string: ");
    fgets(str, sizeof(str), stdin);

    print_ascii(str);

    return 0;
}
