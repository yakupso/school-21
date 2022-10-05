#include <stdio.h>
#include <stdlib.h>
#include "./data_process.h"
#include "../data_libs/data_io.h"

int main() {
    double *data = (double*) calloc(1, sizeof(double));
    int n;

    if (input(data, &n) && normalization(data, n)) {
        output(data, n);
    } else {
        printf("n/a");
    }
    if (data) {
        free(data);
    }
    return 0;
}
