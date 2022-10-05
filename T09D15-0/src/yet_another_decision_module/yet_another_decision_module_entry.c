#include <stdlib.h>
#include <stdio.h>
#include "../data_libs/data_io.h"
#include "./decision.h"

int main() {
    double *data = (double*) calloc(1, sizeof(double));
    int n;
    if (input(data, &n)) {
        if (make_decision(data, n))
            printf("YES");
        else
            printf("NO");
    } else {
        printf("n/a");
    }
    if (data) {
        free(data);
    }
    return 0;
}
