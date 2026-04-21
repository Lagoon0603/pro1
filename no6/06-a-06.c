#include <stdio.h>
#include <stdlib.h>

struct data {
    int num;
    struct data *fp;
    struct data *bp;
};

void push(struct data* sentinel, int n) {
    printf("push %d\n", n);
    struct data* new = (struct data*)malloc(sizeof(struct data));
    if (new == NULL) {
        exit(1);
    }
    new->num = n;

    new->fp = sentinel;
    new->bp = sentinel->bp;
    sentinel->bp->fp = new;
    sentinel->bp = new;
}

int pop_queue(struct data* sentinel) {
    if (sentinel->fp == sentinel) {
        printf("list is empty.\n");
        return -1;
    }

    struct data* target = sentinel->fp;
    int val = target->num;

    sentinel->fp = target->fp;
    target->fp->bp = sentinel;

    free(target);
    printf("pop %d(queue)\n", val);
    return val;
}

int pop_stack(struct data* sentinel) {
    if (sentinel->bp == sentinel) {
        printf("list is empty.\n");
        return -1;
    }

    struct data* target = sentinel->bp;
    int val = target->num;

    sentinel->bp = target->bp;
    target->bp->fp = sentinel;

    free(target);
    printf("pop %d(stack)\n", val);
    return val;
}

void print_data(struct data* sentinel) {
    struct data* current = sentinel->fp;
    printf("stored nums :");
    while (current != sentinel) {
        printf(" %d", current->num);
        current = current->fp;
    }
    printf("\n");
}

int main() {
    struct data sentinel;
    sentinel.fp = sentinel.bp = &sentinel;

    push(&sentinel, 1);
    print_data(&sentinel);
    push(&sentinel, 2);
    print_data(&sentinel);
    push(&sentinel, 3);
    print_data(&sentinel);
    pop_queue(&sentinel);
    print_data(&sentinel);
    pop_stack(&sentinel);
    print_data(&sentinel);
    
    struct data* current = sentinel.fp;
    while (current != &sentinel) {
        struct data* temp = current;
        current = current->fp;
        free(temp);
    }

    return 0;
}