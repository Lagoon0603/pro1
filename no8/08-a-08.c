#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#define DEFAULT_FNAME   "sample-text-1.txt"
#define MAX_TARGET     256

char *read_document(const char *, size_t*);
void free_document(char *);
void highlight_word(const char *, const char *, const char *);

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

char *search_string(char *dptr, char *tptr)
{
    int table[256];
    int len = strlen(tptr);
    int i;
    int shift;
    int matched_count;
    char *p_text;
    char *p_pat;
    size_t d_len;
    char *doc_end;
    char *current_end;

    if (len == 0) return NULL;

    // Build table
    for (i = 0; i < 256; i++) {
        table[i] = len;
    }
    for (i = 0; i < len - 1; i++) {
        table[(unsigned char)tptr[i]] = len - 1 - i;
    }

    d_len = strlen(dptr);
    if (d_len < len) return NULL;

    doc_end = dptr + d_len;
    current_end = dptr + len - 1;

    while (current_end < doc_end) {
        p_text = current_end;
        p_pat = tptr + len - 1;
        matched_count = 0;

        while (p_pat >= tptr && *p_text == *p_pat) {
            p_text--;
            p_pat--;
            matched_count++;
        }

        if (p_pat < tptr) {
            // Found
            return p_text + 1;
        }

        // Mismatch
        shift = table[(unsigned char)*p_text] - matched_count;
        if (shift < 1) shift = 1;

        current_end += shift;
    }

    return NULL;
}

int your_main(char *document, size_t doc_size)
{
    char target[MAX_TARGET];
    char *ptr = document;

    printf("search? ");
    if (fgets(target, sizeof(target), stdin) == NULL) {
        return 0;
    }
    chop(target);

    if (strlen(target) == 0) return 0;

    while ((ptr = search_string(ptr, target)) != NULL) {
        highlight_word(document, ptr, target);
        ptr++;
    }

    return 0;
}

int main(int argc, char *argv[]) 
{
    char *document, *fname = DEFAULT_FNAME;
    size_t doc_size;
    int ret_code;

    while (*++argv) fname = *argv;
    document = read_document(fname, &doc_size);
    
    ret_code = your_main(document, doc_size);

    free_document(document);

    return ret_code;
}

char *read_document(const char *fname, size_t *n)
{
    FILE *fp;
    struct stat stat_buf;
    size_t file_size;
    char *buf;

    if ((fp = fopen(fname, "r")) == NULL) {
        perror(fname);
        exit(1);
    }
    if ((fstat(fileno(fp), &stat_buf) == -1)) {
        perror(fname);
        exit(1);
    }
    file_size = stat_buf.st_size;
    if ((buf = (char*)malloc(file_size + 1)) == NULL) {
        fprintf(stderr, "out of memory\n");
        exit(1);
    }
    if ((*n = fread(buf, sizeof(char), file_size, fp)) != file_size) {
        if (ferror(fp)) {
            perror(fname);
            exit(1);                 
        }
    }
    fclose(fp);
    buf[*n] = '\0';

    return buf;
}

void free_document(char *buf)
{
    free(buf);
}

void highlight_word(const char *document, const char *dptr, const char *target)
{
    const char *p;

    p = dptr - document < 20 ? document : dptr - 20;
    while (p < dptr) printf("%c", *p++);
    while (p < dptr + strlen(target)) 
        printf("\x1b[4m\x1b[31m%c\x1b[0m\x1b[39m", *p++);
    while (*p != '\0' && p < dptr + strlen(target) + 20) 
        printf("%c", *p++);
    putchar('\n');
}
