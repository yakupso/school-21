#include <stdio.h>

#define MAX_SZ 100

int input(int *A, int *n, int *c);
void output(int *A, int n);
void move(int *A, int n, int c);

int main() {
    int A[MAX_SZ], n, c;
    if (input(A, &n, &c) == 1) {
        move(A, n, c);
        output(A, n);
    } else {
        printf("n/a");
    }
    return 0;
}

// доработать проверку на ошибки
int input(int *A, int *n, int *c) {
    int flag = 0;
    char ch;
    if (scanf("%d%c", n, &ch) == 2 && ch == '\n') {
        flag = 0;
    } else {
        flag = 2;
    }
    for (int *p = A; p - A < *n && !flag; p++) {
        if (scanf("%d%c", p, &ch) == 2) {
            if (ch == ' ') {
                flag = 0;
            } else if (ch == '\n') {
                flag = 1;
            } else {
                flag = 2;
            }
        } else {
            flag = 2;
        }
    }
    if (!(scanf("%d%c", c, &ch) == 2 && ch == '\n' && flag == 1)) {
        flag = 2;
    }
    return flag;
}

void output(int *A, int n) {
    for (int i = 0; i < n; i++) {
        if (i < n - 1) {
            printf("%d ", A[i]);
        } else {
            printf("%d", A[i]);
        }
    }
}

void move(int *A, int n, int c) {
    int B[n];
    if (c < 0) {
        c += n;
    }
    if (c > n) {
        c %= n;
    }
    for (int i = 0; i < n; i++) {
        if (n - c - i - 1 > 0) {
            B[i] = A[i + c];
        } else {
            B[i] = A[i + c - n];
        }
    }
    for (int i = 0; i < n; i++) {
        A[i] = B[i];
    }
}

