#include <stdio.h>

int main() {
    double x, y;
    double r = 5.;
    char c;
    if (scanf("%lf %lf%c", &x, &y, &c) == 3 && (c == ' ' || c == '\n')) {
        if ((x * x + y * y) < (r * r)) {
            printf("%s", "GOTCHA");
        } else {
            printf("%s", "MISS");
        }
    } else {
        printf("n/a");
    }
    return 0;
}
