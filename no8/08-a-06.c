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

char *strrev(char *dst, char *src, size_t n)
{
    size_t len = strlen(src);
    size_t i;

    for (i = 0; i < n - 1 && i < len; i++) {
        dst[i] = src[len - 1 - i];
    }
    dst[i] = '\0';
    return dst;
}

int main() 
{
    char src[SRC_LEN], dst[DST_LEN];

    printf("input a string: ");
    fgets(src, SRC_LEN, stdin);
    chop(src);

    printf("reversed: %s\n", strrev(dst, src, DST_LEN));

    return 0;
}
