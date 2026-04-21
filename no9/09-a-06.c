#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int is_word_char(int c) {
    return isalnum(c) || c == '\'' || c == '-';
}

int is_word_separator(int c) {
    return c == ' ' || c == '\n' || c == ',' || c == ':' || c == ';' || c == '"';
}

int is_sentence_separator(int c) {
    return c == '.' || c == '?' || c == '!';
}

int main(int argc, char *argv[]) {
    FILE *fp;
    long file_size;
    char *buf;
    int word_count = 0;
    int sentence_count = 0;
    int in_word = 0;
    int i;

    if (argc != 2) {
        fprintf(stderr, "usage: %s filename\n", argv[0]);
        exit(1);
    }

    if ((fp = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "Cannot open file: %s\n", argv[1]);
        exit(1);
    }

    if (fseek(fp, 0, SEEK_END) != 0) {
        perror("fseek");
        fclose(fp);
        exit(1);
    }
    file_size = ftell(fp);
    if (file_size == -1) {
        perror("ftell");
        fclose(fp);
        exit(1);
    }
    rewind(fp);

    if ((buf = (char *)malloc(file_size * sizeof(char))) == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        fclose(fp);
        exit(1);
    }

    if (fread(buf, sizeof(char), file_size, fp) != (size_t)file_size) {
        if (ferror(fp)) {
            perror("fread");
            free(buf);
            fclose(fp);
            exit(1);
        }
    }
    fclose(fp);

    for (i = 0; i < file_size; i++) {
        char c = buf[i];

        if (is_word_char(c)) {
            if (!in_word) {
                in_word = 1;
                word_count++;
            }
        } else if (is_word_separator(c)) {
            in_word = 0;
        } else if (is_sentence_separator(c)) {
            in_word = 0;
            sentence_count++;
        } else {
            fprintf(stderr, "Error: Invalid character '%c' detected.\n", c);
            free(buf);
            exit(1);
        }
    }

    printf("%s contains:\n", argv[1]);
    printf("\t%d words and %d sentences\n", word_count, sentence_count);

    free(buf);
    return 0;
}
