#include "stack_double.h"


struct stack_double *push_double(struct stack_double *root, const double doors) {
    struct stack_double *pst;
    pst = (struct stack_double *)malloc(1 * sizeof(struct stack_double));
    pst -> prev  = root;
    pst -> value = doors;
    return pst;
}

struct stack_double *pop_double(struct stack_double *root) {
    struct stack_double *pst;
    pst = root -> prev;
    free(root);
    return pst;
}

void destroy_double(struct stack_double *root) {
    while (root != NULL) {
        root = pop_double(root);
    }
}
