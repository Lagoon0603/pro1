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

struct data_t *insert_pos(struct data_t *p, struct data_t *w) {
    struct data_t *current = p->fp;

    while (current != p) {
        if (current->data > w->data) {
            return current;
        }
        current = current->fp;
    }
    return p;
}

void printasc(struct data_t *p) {
    struct data_t *current = p->fp;
    while (current != p) {
        printf("%d", current->data);
        current = current->fp;
    }
    printf("\n");
}

void printdsc(struct data_t *p) {
    struct data_t *current = p->bp;
    while (current != p) {
        printf("%d", current->data);
        current = current->bp;
    }
    printf("\n");
}

int main(void) {
    int d;
    struct data_t head;
    struct data_t *new, *pos;

    head.fp = &head;
    head.bp = &head;

    while (scanf("%d", &d) != EOF) {
        new = (struct data_t *)malloc(sizeof(struct data_t));
        if (new == NULL) {
            return 1;
        }
        new->data = d;

        pos = insert_pos(&head, new);
        insert(pos, new);
    }

    printasc(&head);
    printdsc(&head);

    struct data_t *current = head.fp;
    while (current != &head) {
        struct data_t *temp = current;
        current = current->fp;
        free(temp);
    }

    return 0;
}