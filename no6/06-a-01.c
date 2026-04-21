#include <stdio.h>
#include <stdlib.h>

struct number {
    int data;
    struct number *next;
};

int main(void) {
    struct number *head = NULL;
    struct number *tail = NULL;
    int i;

    printf("input 5 numbers :\n");

    for (i = 0; i < 5; i++) {
        struct number *new = (struct number *)malloc(sizeof(struct number));
        if (new == NULL) {
            return 1;
        }  

        scanf("%d", &new->data);
        new->next = NULL;

        if (head == NULL) {
            head = new;
            tail = new;
        } else {
            tail->next = new;
            tail = new;
        }
    }

    printf("number list: ");
    struct number *current = head;
    while (current != NULL) {
        printf("%d, ", current->data);
        current = current->next;
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