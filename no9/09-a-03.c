#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *fp_in, *fp_out;
    int ch;
    const char *infile = "09-a-01.txt";
    const char *outfile = "09-a-03.txt";

    fp_in = fopen(infile, "r");
    if (fp_in == NULL) {
        perror(infile);
        return 1;
    }

    fp_out = fopen(outfile, "a");
    if (fp_out == NULL) {
        perror(outfile);
        fclose(fp_in);
        return 1;
    }

    while ((ch = fgetc(fp_in)) != EOF) {
        fputc(ch, fp_out);
    }

    fclose(fp_in);
    fclose(fp_out);

    return 0;
}
