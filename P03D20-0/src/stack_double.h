#ifndef SRC_STACK_DOUBLE_H_
#define SRC_STACK_DOUBLE_H_

#include <stdio.h>
#include <stdlib.h>

struct stack_double {
    double value;
    struct stack_double * prev;
};

struct stack_double* push_double(struct stack_double *root, const double doors);
struct stack_double* pop_double(struct stack_double *root);
void destroy_double(struct stack_double *root);

#endif  // SRC_STACK_DOUBLE_H_

