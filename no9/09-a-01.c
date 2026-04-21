#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *fp;
    int ch;
    const char *filename = "09-a-01.txt";

    fp = fopen(filename, "r");

    if (fp == NULL) {
        perror(filename);
        return 1;
    }

    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch);
    }

    fclose(fp);

    return 0;
}
