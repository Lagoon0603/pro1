#include <stdio.h>
#include <stdlib.h>

struct data_t {
    int num;
    int count;
    struct data_t *fp;
    struct data_t *bp;
};

void insert(struct data_t *p, struct data_t *w) {
    w->fp = p;
    w->bp = p->bp;
    p->bp->fp = w;
    p->bp = w;
}

int main(void) {
    int d;
    struct data_t head;
    struct data_t *current, *new;
    int found;

    head.fp = &head;
    head.bp = &head;

    head.num = -1; 
    head.count = -1;

    while (scanf("%d", &d) != EOF) {
        found = 0;
        current = head.fp;


        while (current != &head) {
            if (current->num == d) {
                current->count++;
                found = 1;
                break;
            }
            if (current->num > d) {
                break;
            }
            current = current->fp;
        }

        if (found == 0) {
            new = (struct data_t *)malloc(sizeof(struct data_t));
            if (new == NULL) {
                return 1;
            }
            new->num = d;
            new->count = 1;
            
            insert(current, new);
        }
    }

    current = head.fp;
    while (current != &head) {
        printf("[%d] : %d\n", current->num, current->count);
        current = current->fp;
    }

    current = head.fp;
    while (current != &head) {
        struct data_t *temp = current;
        current = current->fp;
        free(temp);
    }

    return 0;
}