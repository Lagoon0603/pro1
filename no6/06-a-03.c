#include <stdio.h>
#include <stdlib.h>

struct data_t {
    int data;
    struct data_t *fp;
    struct data_t *bp;
};

void insert(struct data_t *p, struct data_t *w) {
    w->fp = p;
    w->bp = p->bp;
    p->bp->fp = w;
    p->bp = w;
}

void printall(struct data_t *p){
    if (p->fp == p && p->bp == p) {
        return;
    }

    struct data_t *current = p;
    struct data_t *head = p->bp;

    while (current != head) {
         printf("[p: %p, bp: %p, fp: %p, data:%d]\n",
               (void*)current, (void*)current->bp, (void*)current->fp, current->data);
        current = current->fp;
    }
}

int main(void) {
    int d;
    struct data_t head;
    struct data_t *new;

    head.fp = &head;
    head.bp = &head;

    for (; scanf("%d", &d) != EOF;) {
        new = (struct data_t *)malloc(sizeof(struct data_t));
        if (new == NULL) {
            return 1;
        }
        new->data = d;
        insert(&head, new);
    }

    printall(head.fp);

    struct data_t *current = head.fp;
    while (current != &head) {
        struct data_t *temp = current;
        current = current->fp;
        free(temp);
    }

    return 0;
}