#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SRC_LEN 256
#define DST_LEN 4

char *chop(char *s)
{
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

void print_ascii2(char *s, size_t n)
{
    int i = 0;

    while (i++ < n)
        printf("%3d ", *s++);
    printf("\n");
}

char *safe_strncpy(char *dst, char *src, size_t n)
{
    size_t i;
    for (i = 0; i < n - 1; i++) {
        if (*src != '\0') {
            dst[i] = *src++;
        } else {
            dst[i] = '\0';
        }
    }
    dst[n - 1] = '\0';
    return dst;
}

int main() 
{
    char src[SRC_LEN], dst[DST_LEN];

    printf("input a string: ");
    fgets(src, SRC_LEN, stdin);
    chop(src);

    printf("copied by strncpy(dst, src, %d): ", DST_LEN);
    print_ascii2(strncpy(dst, src, DST_LEN), DST_LEN);

    printf("copied by safe_strncpy(dst, src, %d): ", DST_LEN);
    print_ascii2(safe_strncpy(dst, src, DST_LEN), DST_LEN);

    return 0;
}
