#ifndef SRC_STACK_H_
#define SRC_STACK_H_

struct stack* init(const int data);
void push(int data, struct stack **head);
int pop(struct stack **head);
void destroy(struct stack *head);

struct stack {
    int data;
    struct stack *next;
};

#endif  // SRC_STACK_H_
