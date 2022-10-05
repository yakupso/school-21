#include <stdio.h>

int max(int a, int b);

int main() {
    int a, b;
    char c;
    if (scanf("%d %d%c", &a, &b, &c) == 3 && (c == ' ' || c == '\n')) {
        int r_max = max(a, b);
        printf("%d", r_max);
    } else {
        printf("%s", "n/a");
    }
    return 0;
}

int max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}
