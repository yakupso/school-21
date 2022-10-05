#include "./data_stat.h"

double max(double *data, int n) {
    double my_max = data[0];
    for (int i = 1; i < n; i++) {
        if (data[i] > my_max) {
            my_max = data[i];
        }
    }
    return my_max;
}

double min(double *data, int n) {
    double my_min = data[0];
    for (int i = 1; i < n; i++) {
        if (data[i] < my_min) {
            my_min = data[i];
        }
    }
    return my_min;
}

double mean(double *data, int n) {
    double res = 0;
    for (int i = 0; i < n; i++) {
        res += data[i];
    }
    res /= n;
    return res;
}

double variance(double *data, int n) {
    double res;
    double sqr_sum = 0., sum = 0.;
    for (int i = 0; i < n; i++) {
        sqr_sum += data[i] * data[i];
        sum += data[i];
    }
    res = (sqr_sum / n) - ((sum / n) * (sum / n));
    return res;
}
