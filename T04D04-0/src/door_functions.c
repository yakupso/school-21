#include <math.h>
#include <stdio.h>

const double PI = 3.14159265358979323846;
const double interval = PI / 20.5;

double var_an(double x);
double lem_ber(double x);
double quatro(double x);

int main() {
    double y_1, y_2, y_3;
    int i = 0;
    for (double x = -PI; x <= PI; x += interval) {
        y_1 = var_an(x);
        y_2 = lem_ber(x);
        y_3 = quatro(x);
        printf("%.7lf | %.7lf | ", x, y_1);
        if (y_2 == -1) {
            printf("- | ");
        } else {
            printf("%.7lf | ", y_2);
        }
        if (y_3 == -1) {
            printf("-\n");
        } else {
            printf("%.7lf\n", y_3);
        }
        i++;
    }
    return 0;
}

double var_an(double x) {
    return 1 / (1 + x * x);
}

double lem_ber(double x) {
    if ((sqrt(1 + 4 * x * x) - x * x - 1) > 0) {
        return sqrt(sqrt(1 + 4 * x * x) - x * x - 1);
    } else {
        return -1;
    }
}

double quatro(double x) {
    if (x) {
        return 1 / (x * x);
    } else {
        return -1;
    }
}
