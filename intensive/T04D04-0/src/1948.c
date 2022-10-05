#include <math.h>
#include <stdio.h>

int bsd();
int div(int a, int b, int par);

int main() {
    int num;
    char c;
    if (scanf("%d%c", &num, &c) == 2 && (c == ' ' || c == '\n')) {
        num = bsd(num);
    } else {
        printf("%s", "n/a");
    }
    return 0;
}

int bsd(int num) {
    if (num < 0) {
        num = -num;
    }

    int i = num;
    int j = 0;
    int k;

    while (i > 0) {
        if (div(num, i, 1) == 0) {
            k = i;
            while (k > 0) {
                if (div(i, k, 1) == 0) {
                    j++;
                }
                k--;
            }
            if (j == 2) {
                printf("%d", i);
                return i;
            }
            j = 0;
        }
        i--;
    }
    return i;
}

int div(int a, int b, int par) {
    int count = 0;
    while (a >= 0) {
        a -= b;
        count++;
    }
    a += b;
    count--;
    if (par == 0)
        return count;
    else if (par == 1)
        return a;
    else
        return -1;
}
