#include <stdio.h>
#include <stdlib.h>

int input(int *a, int n);
int input_size(int *n);
void my_sort(int *a, int n);
void output(int *a, int n);

int main() {
    int *a, n;
    if (input_size(&n)) {
        a = (int*) calloc(n, sizeof(int));
        if (input(a, n)) {
            my_sort(a, n);
            output(a, n);
        } else {
            printf("n/a");
        }
    } else {
        printf("n/a");
    }
    free(a);
    return 0;
}

int input_size(int *n) {
    char c;
    int is_valid = 1;
    if (scanf("%d%c", n, &c) == 2 && c == '\n') {
        is_valid = 1;
    } else {
        is_valid = 0;
    }
    return is_valid;
}

int input(int *a, int n) {
    char c;
    int is_valid = 1;
    for (int i = 0; i < n && is_valid; i++) {
        if (scanf("%d%c", &a[i], &c) == 2 && (c == ' ' || c == '\n')) {
        } else {
            is_valid = 0;
        }
    }
    return is_valid;
}

void my_sort(int *a, int n) {
    int tmp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                tmp = a[j + 1];
                a[j + 1] = a[j];
                a[j] = tmp;
            }
        }
    }
}

void output(int *a, int n) {
    for (int i = 0; i < n; i++) {
        if (i < n - 1) {
            printf("%d ", a[i]);
        } else {
            printf("%d", a[i]);
        }
    }
}

