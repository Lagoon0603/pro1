#include <stdio.h>
#include <stdlib.h>

struct student {
    int id;
    int math;
    int science;
    int english;
    double average;
    struct student *fp_id, *bp_id;
    struct student *fp_avg, *bp_avg;
};

void insert_id(struct student *p, struct student *w) {
    w->fp_id = p;
    w->bp_id = p->bp_id;
    p->bp_id->fp_id = w;
    p->bp_id = w;
}

void insert_avg(struct student *p, struct student *w) {
    w->fp_avg = p;
    w->bp_avg = p->bp_avg;
    p->bp_avg->fp_avg = w;
    p->bp_avg = w;
}

int main(void) {
    struct student head_id, head_avg;
    struct student *new, *current;
    int id, math, sci, eng;

    head_id.fp_id = head_id.bp_id = &head_id;
    head_avg.fp_avg = head_avg.bp_avg = &head_avg;

    while (1) {
        printf("Input ID, Math, Science English : ");
        scanf("%d %d %d %d", &id, &math, &sci, &eng);

        if (id < 0) {
            break;
        }

        new = (struct student *)malloc(sizeof(struct student));
        if (new == NULL) return 1;

        new->id = id;
        new->math = math;
        new->science = sci;
        new->english = eng;
        new->average = (double)(math + sci + eng) / 3.0;

        current = head_id.fp_id;
        while (current != &head_id) {
            if (current->id > new->id) {
                break;
            }
            current = current->fp_id;
        }
        insert_id(current, new);

      current = head_avg.fp_avg;
        while (current != &head_avg) {
            if (current->average > new->average) {
                break;
            }
            current = current->fp_avg;
        }
        insert_avg(current, new);
    }

    printf("[ID]\n");
    current = head_id.fp_id;
    while (current != &head_id) {
        printf("ID : %d, Math : %d, Science : %d, English : %d\n",
               current->id, current->math, current->science, current->english);
        current = current->fp_id;
    }

    printf("[Average]\n");
    current = head_avg.fp_avg;
    while (current != &head_avg) {
        printf("Average : %f, ID : %d\n", current->average, current->id);
        current = current->fp_avg;
    }

    current = head_id.fp_id;
    while (current != &head_id) {
        struct student *temp = current;
        current = current->fp_id;
        free(temp);
    }

    return 0;
}