#include <stdio.h>
#include <stdlib.h>

struct number {
    int data;
    struct number *next;
    struct number *prev;
};

int main(void) {
    struct number *head = NULL;
    struct number *tail = NULL;
    struct number *current = NULL;
    int i;

    printf("input 5 numbers :\n");

    for (i = 0; i < 5; i++) {
        current = (struct number *)malloc(sizeof(struct number));
        if (current == NULL) {
            return 1;
        }

        scanf("%d", &current->data);
        current->next = NULL;
        current->prev = tail;

        if (head == NULL) {
            head = current;
            tail = current;
        } else {
            tail->next = current;
            tail = current;
        }
    }

    printf("number list : ");
    current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    printf("number list : ");
    current = tail;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->prev;
    }
    printf("\n");

    current = head;
    while (current != NULL) {
        struct number *temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}