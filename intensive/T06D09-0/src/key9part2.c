#include <stdio.h>

#define LEN 100

int input(int *A, int *n);
void output(int *A, int len_A);
void sum(int *A, int len_A, int *B, int len_B, int *R, int *len_R);
void sub(int *A, int len_A, int *B, int len_B, int *R, int *len_R);
void check(int *A, int *n);
void move(int *A, int n, int c);
int is_bigger(int *A, int *B, int len);

/*
    Беззнаковая целочисленная длинная арифметика
    с использованием массивов.
    Ввод: 
     * 2 длинных числа в виде массивов до 100 элементов
     * В один элемент массива нельзя вводить число > 9
    Вывод: 
     * Результат сложения и разности чисел-массивов
    Пример:
     * 1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 6 1
       2 9

       1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 9 0
       1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 3 2
*/
int main() {
    int A[LEN], B[LEN], RP[LEN], RM[LEN];
    int len_A, len_B, len_RP, len_RM;
    if (input(A, &len_A) == 1 && input(B, &len_B) == 1) {
        if (len_A > len_B) {
            sum(A, len_A, B, len_B, RP, &len_RP);
            sub(A, len_A, B, len_B, RM, &len_RM);
            output(RP, len_RP);
            printf("\n");
            output(RM, len_RM);
        } else if (len_A == len_B && !is_bigger(A, B, len_A)) {
            sum(A, len_A, B, len_B, RP, &len_RP);
            sub(A, len_A, B, len_B, RM, &len_RM);
            output(RP, len_RP);
            printf("\n");
            output(RM, len_RM);
        } else {
            printf("n/a");
        }
    } else {
        printf("n/a");
    }
    return 0;
}

int input(int *A, int *n) {
    int flag = 0;
    char ch;
    for (int i = 0; i < LEN && !flag; i++) {
        if (scanf("%d%c", &A[i], &ch) == 2 && A[i] < 10 && A[i] >= 0) {
            if (ch == ' ') {
                flag = 0;
            } else if (ch == '\n') {
                flag = 1;
                *n = i + 1;
            } else {
                flag = 2;
            }
        } else {
            flag = 2;
        }
    }
    return flag;
}

void output(int *A, int len_A) {
    int count = 0;
    int flag = 1;
    for (int i = 0; i < len_A - 1 && flag; i++) {
        if (A[i] == 0) {
            count++;
        } else {
            flag = 0;
        }
    }
    for (int i = count; i < len_A; i++) {
        if (i < len_A - 1) {
            printf("%d ", A[i]);
        } else {
            printf("%d", A[i]);
        }
    }
}

void sum(int *A, int len_A, int *B, int len_B, int *R, int *len_R) {
    *len_R = (len_A > len_B) ? (len_A + 1) : (len_B + 1);
    len_A--;
    len_B--;
    for (int i = 0; i < *len_R; i++) {
        R[i] = 0;
    }
    for (int i = 0; i < len_A + 1; i++) {
        if (len_B >= i) {
            if (A[len_A - i] + B[len_B - i] > 9) {
                R[*len_R - i - 2] += (A[len_A - i] + B[len_B - i]) / 10;
                R[*len_R - i - 1] += (A[len_A - i] + B[len_B - i]) % 10;
            } else {
                R[*len_R - i - 1] += A[len_A - i] + B[len_B - i];
            }
        } else {
            R[*len_R - i - 1] += A[len_A - i];
        }
    }
    check(R, len_R);
}

void sub(int *A, int len_A, int *B, int len_B, int *R, int *len_R) {
    *len_R = (len_A > len_B) ? (len_A + 1) : (len_B + 1);
    len_A--;
    len_B--;
    for (int i = 0; i < *len_R; i++) {
        R[i] = 0;
    }
    for (int i = 0; i < len_A + 1; i++) {
        if (len_B >= i) {
            if (A[len_A - i] - B[len_B - i] < 0) {
                R[*len_R - i - 2] -= 1;
                R[*len_R - i - 1] += 10;
                R[*len_R - i - 1] += (A[len_A - i] - B[len_B - i]);
            } else {
                R[*len_R - i - 1] += A[len_A - i] - B[len_B - i];
            }
        } else {
            R[*len_R - i - 1] += A[len_A - i];
        }
    }
    check(R, len_R);
}

void check(int *A, int *n) {
    for (int i = 1; i < *n - 1; i++) {
        if (A[i] >= 10) {
            A[i - 1] = A[i] / 10;
            A[i] %= 10;
        }
    }
}

int is_bigger(int *A, int *B, int len) {
    int is_bigger_v = 0;
    for (int i = 0; i < len && !is_bigger_v; i++) {
        if (A[i] >= B[i]) {
            is_bigger_v = 0;
        } else {
            is_bigger_v = 1;
        }
    }
    return is_bigger_v;
}
