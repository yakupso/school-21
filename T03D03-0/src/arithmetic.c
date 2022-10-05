#include <stdio.h>

int sum(int a, int b);
int diff(int a, int b);
int div(int a, int b);
int mult(int a, int b);

int main() {
    int a, b;
    char c;
    if (scanf("%d %d%c", &a, &b, &c) == 3 && (c == ' ' || c == '\n')) {
        int r_sum, r_diff, r_div, r_mult;
        r_sum = sum(a, b);
        r_diff = diff(a, b);
        r_mult = mult(a, b);
        r_div = div(a, b);

        if (b != 0) {
            printf("%d %d %d %d", r_sum, r_diff, r_mult, r_div);
        } else {
            printf("%d %d %d %s", r_sum, r_diff, r_mult, "n/a");
        }
    } else {
        printf("%s", "n/a");
    }
    return 0;
}

int sum(int a, int b) { return a + b; }

int diff(int a, int b) { return a - b; }

int mult(int a, int b) { return a * b; }

int div(int a, int b) {
    if (b != 0) {
        return a / b;
    }
    return -1;
}
