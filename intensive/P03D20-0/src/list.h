#ifndef SRC_LIST_H_
#define SRC_LIST_H_

#include <stdio.h>
#include <stdlib.h>

struct node {
    char c;
    int priority;
    struct node * next;
};

struct node *init_list(const char ch, const int ipriority);
struct node* add_symbol_list(struct node* elem, const char ch, const int ipriority);
int find_list(char ch, struct node* root);
void destroy_list(struct node* root);
#endif  // SRC_LIST_H_

