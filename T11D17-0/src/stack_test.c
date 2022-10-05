#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

#define DATASZ 15

char *push_test(struct stack **head, int *data);
char *pop_test();

int main() {
    int data[DATASZ] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
    struct stack *head = init(data[0]);
    printf("push_test: %s\n", push_test(&head, data));
    printf("pop_test: %s", pop_test(&head));
    destroy(head);
    return 0;
}

char *push_test(struct stack **head, int *data) {
    for (int i = 1; i < DATASZ; i++) {
        push(data[i], head);
    }
    int is_equal = 1;
    struct stack *curr_elem = *head;
    for (int i = DATASZ - 1; i > 0; i--) {
        if (data[i] != curr_elem->data) {
            is_equal = 0;
        }
        curr_elem = curr_elem->next;
    }
    return is_equal ? "SUCCESS" : "FAIL";
}

char *pop_test(struct stack **head) {
    int n = pop(head);
    return n == 14 ? "SUCCESS" : "FAIL";
}
