#include <math.h>
#include <stdio.h>

void code();
void decode();

int main(int argc, char* argv[]) {
    if (argc == 2) {
        if (*argv[1] == '0') {
            code();
        } else if (*argv[1] == '1') {
            decode();
        } else {
            printf("n/a");
        }
    } else {
        printf("n/a");
    }
    return 0;
}

void code() {
    char c, c1;
    while (c1 != '\n') {
        scanf("%c%c", &c, &c1);
        if (c1 != ' ' && c1 != '\n') {
            printf("n/a");
            break;
        }
        printf("%X", c);
        if (c1 != '\n') {
            printf("%c", c1);
        }
    }
}

void decode() {
    int n;
    char c;
    while (c != '\n') {
        scanf("%2X%c", &n, &c);
        if (c != ' ' && c != '\n') {
            printf("n/a");
            break;
        }
        printf("%c", n);
        if (c != '\n') {
            printf("%c", c);
        }
    }
}
