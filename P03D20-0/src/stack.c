#include "stack.h"

struct stack *init(const char doors) {
    struct stack *pst;
    pst = (struct stack*)malloc(1 * sizeof(struct stack));
    pst -> prev = NULL;
    pst -> value = doors;
    return pst;
}

struct stack *push(struct stack *root, const char doors) {
    struct stack *pst;
    pst = (struct stack *)malloc(1 * sizeof(struct stack));
    pst -> prev  = root;
    pst -> value = doors;
    return pst;
}

struct stack *pop(struct stack *root) {
    struct stack *pst;
    pst = root -> prev;
    free(root);
    return pst;
}

void destroy(struct stack *root) {
    while (root != NULL) {
        root = pop(root);
    }
}
