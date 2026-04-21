#include <stdio.h>
#include <string.h>

size_t my_strlen(const char *s) {
    size_t len = 0;
    while (*s != '\0') {
        len++;
        s++;
    }
    return len;
}

size_t my_strcmp(const char *s1, const char *s2) {
    while (*s1 != '\0' || *s2 != '\0') {
        if (*s1 != *s2) {
            return 0;
        }
        s1++;
        s2++;
    }
    return 1;
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
    char str1[256];
    char str2[256];

    printf("input 1st string: ");
    fgets(str1, sizeof(str1), stdin);
    chop(str1);

    printf("input 2nd string: ");
    fgets(str2, sizeof(str2), stdin);
    chop(str2);

    printf("1st len: strlen == %lu, my_strlen == %lu\n", strlen(str1), my_strlen(str1));
    printf("2nd len: strlen == %lu, my_strlen == %lu\n", strlen(str2), my_strlen(str2));

    if (my_strcmp(str1, str2)) {
        printf("%s == %s\n", str1, str2);
    } else {
        printf("%s != %s\n", str1, str2);
    }

    return 0;
}
