#include "./data_io.h"
#include <stdlib.h>
#include <stdio.h>

int input(double *data, int *n) {
    int is_valid = 1;
    if (!(scanf("%d", n) == 1)) {
        is_valid = 0;
    } else {
        data = realloc(data, *n * sizeof(double));
        for (int i = 0; i < *n && is_valid; i++) {
            if (!(scanf("%lf", &data[i]) == 1)) {
                is_valid = 0;
            }
        }
    }
    return is_valid;
}

void output(double *data, int n) {
    for (int i = 0; i < n; i++) {
        if (i < n - 1)
            printf("%.2lf ", data[i]);
        else
            printf("%.2lf", data[i]);
    }
}
