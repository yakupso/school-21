#include <math.h>
#include <stdio.h>

int main() {
    double x;
    char c;
    if (scanf("%lf%c", &x, &c) == 2 && (c == ' ' || c == '\n')) {
        double y = 7e-3 * x * x * x * x + ((22.8 * pow(x, 1. / 3.) - 1e3) * x + 3) / (x * x / 2) -
                   x * pow(10 + x, 2 / x) - 1.01;
        printf("%.1lf", y);
    } else {
        printf("%s", "n/a");
    }
    return 0;
}
