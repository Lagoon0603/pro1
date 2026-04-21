#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *fp_dest, *fp_src;
    int c;
    int i;

    if (argc < 2) {
        fprintf(stderr, "usage: %s file [file ...]\n", argv[0]);
        exit(1);
    }

    if ((fp_dest = fopen(argv[1], "a")) == NULL) {
        fprintf(stderr, "Cannot open destination file: %s\n", argv[1]);
        exit(1);
    }

    for (i = 2; i < argc; i++) {
        if ((fp_src = fopen(argv[i], "r")) == NULL) {
            fprintf(stderr, "Cannot open source file: %s\n", argv[i]);
            fclose(fp_dest);
            exit(1);
        }

        while ((c = fgetc(fp_src)) != EOF) {
            fputc(c, fp_dest);
        }

        fclose(fp_src);
    }

    fclose(fp_dest);
    return 0;
}