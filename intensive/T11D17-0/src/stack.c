#include <stdlib.h>

#include "stack.h"

struct stack* init(int data) {
    struct stack *first_elem = (struct stack*) malloc(sizeof(struct stack));
    first_elem->data = data;
    first_elem->next = NULL;
    return first_elem;
}

void push(int data, struct stack **head) {
    struct stack *new_elem = (struct stack*) malloc(sizeof(struct stack));
    new_elem->data = data;
    new_elem->next = *head;
    *head = new_elem;
}

int pop(struct stack **head) {
    int n;
    struct stack *tmp = *head;
    *head = (*head)->next;
    n = tmp->data;
    free(tmp);
    return n;
}

void destroy(struct stack *head) {
    struct stack *curr_elem = head;
    struct stack *next_elem;
    while (curr_elem) {
        next_elem = curr_elem->next;
        free(curr_elem);
        curr_elem = next_elem;
    }
}
