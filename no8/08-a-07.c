#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#define DEFAULT_FNAME   "sample-text-1.txt"
#define MAX_TARGET     256

char *read_document(const char *, size_t*);
void free_document(char *);
void highlight_word(const char *, const char *, const char *);

// you can add your code definitions here

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
    char *p_doc, *p_target;

    if (*tptr == '\0') return NULL;

    while (*dptr != '\0') {
        p_doc = dptr;
        p_target = tptr;

        while (*p_doc == *p_target && *p_target != '\0') {
            p_doc++;
            p_target++;
        }

        if (*p_target == '\0') {
            return dptr;
        }
        dptr++;
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