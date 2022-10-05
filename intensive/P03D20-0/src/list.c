#include "list.h"

struct node *init_list(const char ch, const int ipriority) {
    struct node *first = (struct node *)malloc(1 * sizeof(struct node));
    first -> c = ch;
    first -> priority = ipriority;
    first -> next = NULL;
    return first;
}
struct node* add_symbol_list(struct node* elem, const char ch, const int ipriority) {
    struct node *add_node = (struct node *)malloc(1 * sizeof(struct node));
    add_node -> c = ch;
    add_node -> priority = ipriority;
    add_node -> next = elem -> next;
    elem -> next = add_node;
    return add_node;
}

int find_list(char ch, struct node* root) {
    int flag = 1;
    while (root != NULL && flag == 1) {
        if (root -> c == ch) {
            flag = 0;
        } else {
            root = root -> next;
        }
    }
    return root -> c;
}

void destroy_list(struct node *root) {
  struct node *a = root -> next;
  struct node *b = root -> next;
  free(root);
  int i = 1;
  if (b == NULL) {
    i = 0;
  }
  while (i) {
    if (b->next != NULL) {
      b = b->next;
      free(a);
      a = b;
    } else {
      free(b);
      i = 0;
    }
  }
}
