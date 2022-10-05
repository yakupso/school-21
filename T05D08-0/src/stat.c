#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
double variance(int n);

void output_result(int max_v,
                   int min_v,
                   double mean_v,
                   double variance_v);

int main() {
    int n, data[NMAX];
    if (input(data, &n)) {
        output(data, n);
        output_result(max(data, n),
                      min(data, n),
                      mean(data, n),
                      variance(n));
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

void output(int *a, int n) {
    for (int i = 0; i < n; i++) {
        if (i != n - 1)
            printf("%d ", a[i]);
        else
            printf("%d", a[i]);
    }
}

int max(int *a, int n) {
    int my_max = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > my_max) {
            my_max = a[i];
        }
    }
    return my_max;
}

int min(int *a, int n) {
    int my_min = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] < my_min) {
            my_min = a[i];
        }
    }
    return my_min;
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

void output_result(int max_v,
                   int min_v,
                   double mean_v,
                   double variance_v) {
    printf("\n%d %d %.6lf %.6lf", max_v, min_v, mean_v, variance_v);
}
