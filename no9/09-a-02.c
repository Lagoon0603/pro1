#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *fp;
    const char *filename = "09-a-02.txt";

    fp = fopen(filename, "w");

    if (fp == NULL) {
        perror(filename);
        return 1;
    }

    fprintf(fp, "Student ID: 62413535\n");
    fprintf(fp, "Kumpei Doi\n");

    fclose(fp);

    return 0;
}
