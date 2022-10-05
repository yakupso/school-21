#include <stdio.h>

#define ARR_SZ 10

int input(int *a, int n);
void my_sort(int *a, int n);
void output(int *a, int n);

int main() {
    int a[ARR_SZ];
    if (input(a, ARR_SZ)) {
        printf("n/a");
        return 0;
    }
    my_sort(a, ARR_SZ);
    output(a, ARR_SZ);
    return 0;
}

int input(int *a, int n) {
    char c;
    for (int *p = a; p - a < n; p++) {
        if (scanf("%d%c", p, &c) != 2 || (c != ' ' && c != '\n')) {
            return 1;
        }
    }
    return 0;
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
        printf("%d ", a[i]);
    }
}
