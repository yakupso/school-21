#include <math.h>
#include <stdio.h>

long int fib(long int a);

int main() {
    long int n;
    char c;
    if (scanf("%ld%c", &n, &c) == 2 && (c == ' ' || c == '\n')) {
        printf("%ld", fib(n));
    } else {
        printf("%s", "n/a");
    }
    return 0;
}

long int fib(long int a) {
    if (a == 1 || a == 2) {
        return 1;
    }
    return fib(a - 1) + fib(a - 2);
}
