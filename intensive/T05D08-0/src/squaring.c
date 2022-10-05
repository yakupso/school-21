#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int *n);
void squaring(int *a, int *n);

int main() {
    int n, data[NMAX];
    if (input(data, &n)) {
        squaring(data, &n);
        output(data, &n);
    }

    return 0;
}

int input(int *a, int *n) {
    char c;
    if (scanf("%d%c", n, &c) == 2 && c == '\n' && *n <= NMAX && *n > 0) {
        for (int *p = a; p - a < *n; p++) {
            if (scanf("%d%c", p, &c) != 2 || (c != '\n' && c != ' ')) {
                printf("n/a");
                return 0;
            }
        }
    } else {
        printf("n/a");
        return 0;
    }
    return 1;
}

void output(int *a, int *n) {
    for (int i = 0; i < *n; i++) {
        if (i != *n - 1)
            printf("%d ", a[i]);
        else
            printf("%d", a[i]);
    }
}

void squaring(int *a, int *n) {
    for (int i = 0; i < *n; i++) {
        a[i] *= a[i];
    }
}


