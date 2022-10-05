#include <stdio.h>
#include <stdlib.h>
#include "print_module.h"
#include "documentation_module.h"

int main() {
    print_log(printchar, Module_load_success_message);
    int *availability_mask = NULL;
    char *documents[15] = {Documents};
    availability_mask = check_available_documentation_module(validate, Documents_count, Documents);

    // Output availability for each document....
    for (int i = 0; i < Documents_count - 1; i++) {
        if (availability_mask[i] == 0) {
            printf("%s: unavailable,\n", documents[i]);
        } else {
            printf("%s: available,\n", documents[i]);
        }
        if (i == Documents_count - 2) {
            if (availability_mask[i + 1] == 0) {
                printf("%s: unavailable", documents[i + 1]);
            } else {
                printf("%s: available", documents[i + 1]);
            }
        }
    }
    if (availability_mask != NULL) {
        free(availability_mask);
    }
    return 0;
}
