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

char *chop(char *s) {
    char *p = s;
    while (*p != '\0') {
        if (*p == '\n') {
            *p = '\0';
            break;
        }
        p++;
    }
    return s;
}

int main(void) {
    char str[4];

    printf("input string: ");
    fgets(str, sizeof(str), stdin);

    printf("before chop: ");
    print_ascii(str);

    chop(str);

    printf("after chop: ");
    print_ascii(str);

    return 0;
}
