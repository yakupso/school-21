#ifndef SRC_STACK_H_
#define SRC_STACK_H_

#include <stdio.h>
#include <stdlib.h>

struct stack {
    char value;
    struct stack * prev;
};

struct stack* init(const char doors);
struct stack* push(struct stack *root, const char doors);
struct stack* pop(struct stack *root);
void destroy(struct stack *root);

#endif  // SRC_STACK_H_


