#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "./door_struct.h"
#include "./list.h"

#define DOORS_COUNT 15
#define MAX_ID_SEED 10000

void initialize_doors(struct door *doors);
void sort_doors(struct door *doors);
char* add_door_test(struct node *head, struct door* doors);
char* remove_door_test(struct node **head);

int main() {
    struct door doors[DOORS_COUNT];
    initialize_doors(doors);
    sort_doors(doors);
    struct node *head = init(&doors[0]);
    printf("add_door_test: %s", add_door_test(head, doors));
    printf("\nremove_door_test: %s", remove_door_test(&head));
    destroy(head);
    return 0;
}

char* add_door_test(struct node *head, struct door* doors) {
    for (int i = DOORS_COUNT - 1; i > 0; i--) {
        add_door(head, &doors[i]);
    }
    const int results[DOORS_COUNT] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
    int is_equal = 1;
    for (int i = 0; i < DOORS_COUNT; i++) {
        if (find_door(i, head) && find_door(i, head)->door_obj.id == results[i]) {
        } else {
            is_equal = 0;
        }
    }
    return is_equal ? "SUCCESS" : "FAIL";
}

char* remove_door_test(struct node **head) {
    *head = remove_door(*head, *head);
    int results_1[DOORS_COUNT - 1] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
    int is_equal = 1;
    for (int i = 0; i < DOORS_COUNT - 1 && is_equal; i++) {
        if (find_door(results_1[i], *head) != 0 &&
            find_door(results_1[i], *head)->door_obj.id == results_1[i]) {
        } else if (!find_door(results_1[i], *head)) {
        } else {
            is_equal = 0;
        }
    }
    *head = remove_door(find_door(8, *head), *head);
    int results_2[DOORS_COUNT - 2] = {1, 2, 3, 4, 5, 6, 7, 9, 10, 11, 12, 13, 14};
    for (int i = 0; i < DOORS_COUNT - 2 && is_equal; i++) {
        if (find_door(results_2[i], *head) != 0 &&
            find_door(results_2[i], *head)->door_obj.id == results_2[i]) {
        } else if (!find_door(results_2[i], *head)) {
        } else {
            is_equal = 0;
        }
    }
    return is_equal ? "SUCCESS" : "FAIL";
}

void initialize_doors(struct door* doors) {
    srand(time(0));
    int seed = rand() % MAX_ID_SEED;
    for (int i = 0; i < DOORS_COUNT; i++) {
        doors[i].id = (i + seed) % DOORS_COUNT;
        doors[i].status = rand() % 2;
    }
}

void sort_doors(struct door *doors) {
    struct door tmp;
    for (int i = 0; i < DOORS_COUNT; i++) {
        for (int j = 0; j < DOORS_COUNT - i - 1; j++) {
            if (doors[j].id > doors[j + 1].id) {
                tmp = doors[j + 1];
                doors[j + 1] = doors[j];
                doors[j] = tmp;
            }
        }
    }
}

