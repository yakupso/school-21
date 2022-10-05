#include <stdlib.h>
#include "./list.h"
#include "./door_struct.h"

struct node* init(const struct door *door) {
    struct node *first_elem = (struct node*) malloc(sizeof(struct node));
    first_elem->door_obj = *door;
    first_elem->next = 0;
    return first_elem;
}

struct node* add_door(struct node *elem, const struct door *door) {
    struct node *new_elem = (struct node*) malloc(sizeof(struct node));
    new_elem->door_obj = *door;
    new_elem->next = elem->next;
    elem->next = new_elem;
    return new_elem;
}

struct node* find_door(int door_id, struct node *root) {
    struct node *curr_elem = root;
    while (curr_elem != 0 && curr_elem->door_obj.id != door_id) {
        curr_elem = curr_elem->next;
    }
    return curr_elem ? curr_elem : 0;
}

struct node* remove_door(struct node *elem, struct node *root) {
    struct node *curr_elem = root;
    // curr_elem->door_obj.id != elem->door_obj.id
    if (root && elem) {
        if (curr_elem != elem) {
            while (curr_elem->next != NULL && curr_elem->next != elem) {
                curr_elem = curr_elem->next;
            }
            if (curr_elem->next != NULL) {
                curr_elem->next = elem->next;
                free(elem);
            }
        } else {
            root = curr_elem->next;
            free(curr_elem);
        }
    }
    return root;
}

void destroy(struct node *root) {
    struct node *curr_elem = root;
    struct node *next_elem;
    while (curr_elem) {
        next_elem = curr_elem->next;
        free(curr_elem);
        curr_elem = next_elem;
    }
}
