/*
    Search module for the desired value from data array.

    Returned value must be:
        - "even"
        - ">= mean"
        - "<= mean + 3 * sqrt(variance)"
        - "!= 0"

        OR

        0
*/
#include <stdio.h>
#include <math.h>
#define NMAX 10

int input(int *a, int *n);
void output(int n);
double mean(int *a, int n);
double variance(int n);
void solver(int *a, int n, int mean_v, int variance_v, int *r);

int main() {
    int n, r, data[NMAX];
    if (input(data, &n)) {
        solver(data,
               n,
               mean(data, n),
               variance(n),
               &r);
        output(r);
    }

    return 0;
}

int input(int *a, int *n) {
    char c;
    if (scanf("%d%c", n, &c) == 2 && c == '\n' && *n <= NMAX) {
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

void output(int r) {
    printf("%d", r);
}

double mean(int *a, int n) {
    double res = 0;
    for (int i = 0; i < n; i++) {
        res += a[i];
    }
    res /= n;
    return res;
}

double variance(int n) {
    double res = (n * n - 1) / 12.;
    return res;
}

void solver(int *a, int n, int mean_v, int variance_v, int *r) {
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0 && a[i] >= mean_v && a[i] <= mean_v + 3 * sqrt(variance_v) && a[i] != 0) {
            *r = a[i];
        }
    }
}
