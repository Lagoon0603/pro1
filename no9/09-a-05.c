#include <stdio.h>
#include <stdlib.h>

#define MAX_LINES 10000

int main(int argc, char *argv[]) {
    FILE *fp_in, *fp_out;
    fpos_t line_pos[MAX_LINES];
    int line_count = 0;
    int c;
    int i;

    if (argc != 3) {
        fprintf(stderr, "usage: %s input_file output_file\n", argv[0]);
        exit(1);
    }

    if ((fp_in = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "Cannot open input file: %s\n", argv[1]);
        exit(1);
    }

    if ((fp_out = fopen(argv[2], "w")) == NULL) {
        fprintf(stderr, "Cannot open output file: %s\n", argv[2]);
        fclose(fp_in);
        exit(1);
    }

    fgetpos(fp_in, &line_pos[line_count]);
    
    if ((c = fgetc(fp_in)) != EOF) {
        line_count++;
        rewind(fp_in);
    } else {
        fclose(fp_in);
        fclose(fp_out);
        return 0;
    }

    while ((c = fgetc(fp_in)) != EOF) {
        if (c == '\n') {
            fpos_t p;
            fgetpos(fp_in, &p);
            
            int next = fgetc(fp_in);
            if (next != EOF) {
                if (line_count < MAX_LINES) {
                    line_pos[line_count++] = p;
                } else {
                    fprintf(stderr, "Too many lines (max %d)\n", MAX_LINES);
                    break; 
                }
                fsetpos(fp_in, &p);
            }
        }
    }

    for (i = line_count - 1; i >= 0; i--) {
        fsetpos(fp_in, &line_pos[i]);
        while ((c = fgetc(fp_in)) != EOF) {
            fputc(c, fp_out);
            if (c == '\n') break;
        }
    }

    fclose(fp_in);
    fclose(fp_out);
    return 0;
}
