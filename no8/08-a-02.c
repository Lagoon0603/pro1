#include <stdio.h>

int main(void) {
    char str[256];
    int i = 0;

    printf("input string: ");
    fgets(str, sizeof(str), stdin);

    while (str[i] != '\0') {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] += 'a' - 'A';
        } else if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] -= 'a' - 'A';
        }
        i++;
    }

    printf("%s", str);

    return 0;
}
