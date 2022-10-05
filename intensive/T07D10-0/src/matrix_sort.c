#include <stdio.h>
#include <stdlib.h>

#define MAXSZ 100

int menu();
void choice_2(int M, int N);
void choice_3(int M, int N);
void choice_4(int M, int N);
int input_size(int *M, int *N);
int input_matrix(int **matrix, int M, int N);
void output_matrix(int **matrix, int M, int N);
void sort(int **matrix, int M, int N);

int main() {
    int M, N;
    int choice = menu();
    if (choice && input_size(&M, &N) && M > 0 && N > 0) {
        if (choice == 1) {
            choice_2(M, N);
        } else if (choice == 2) {
            choice_3(M, N);
        } else if (choice == 3) {
            choice_4(M, N);
        } else {
            printf("n/a");
        }
    } else {
        printf("n/a");
    }
    return 0;
}

int menu() {
    int choice;
    char c;
    if (!(scanf("%d%c", &choice, &c) == 2 && c == '\n' && choice > 0 && choice < 5)) {
        choice = 0;
    }
    return choice;
}

void choice_2(int M, int N) {
    int** single_array_matrix = malloc(M * N * sizeof(int) + M * sizeof(int*));
    int* ptr = (int*) (single_array_matrix + M);
    for (int i = 0; i < M; i++)
        single_array_matrix[i] = ptr + N * i;
    if (input_matrix(single_array_matrix, M, N)) {
        sort(single_array_matrix, M, N);
        output_matrix(single_array_matrix, M, N);
    } else {
        printf("n/a");
    }
    free(single_array_matrix);
}

void choice_3(int M, int N) {
    int** pointer_array = malloc(M * sizeof(int*));
    for (int i = 0; i < M; i++)
        pointer_array[i] = malloc(N * sizeof(int));
    //
    for (int i = 0; i < M; i++)
        free(pointer_array[i]);
    if (input_matrix(pointer_array, M, N)) {
        sort(pointer_array, M, N);
        output_matrix(pointer_array, M, N);
    } else {
        printf("n/a");
    }
    for (int i = 0; i < M; i++)
        free(pointer_array[i]);
    free(pointer_array);
}

void choice_4(int M, int N) {
    int** pointer_array = malloc(M * sizeof(int*));
    int* values_array = malloc(M * N * sizeof(int));
    for (int i = 0; i < M; i++)
        pointer_array[i] = values_array + N * i;
    if (input_matrix(pointer_array, M, N)) {
        sort(pointer_array, M, N);
        output_matrix(pointer_array, M, N);
    } else {
        printf("n/a");
    }
    free(values_array);
    free(pointer_array);
}

int input_size(int *M, int *N) {
    char c;
    int is_valid;
    if (scanf("%d %d%c", M, N, &c) == 3 && c == '\n') {
        is_valid = 1;
    } else {
        is_valid = 0;
    }
    return is_valid;
}

int input_matrix(int** matrix, int M, int N) {
    int is_valid = 1;
    char c;
    for (int i = 0; i < M && is_valid; i++) {
        for (int j = 0; j < N && is_valid; j++) {
            if (!(scanf("%d%c", &matrix[i][j], &c) == 2 && (c == ' ' || c == '\n'))) {
                is_valid = 0;
            }
        }
    }
    return is_valid;
}

void output_matrix(int **matrix, int M, int N) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (j < N - 1) {
                printf("%d ", matrix[i][j]);
            } else {
                printf("%d", matrix[i][j]);
            }
        }
        if (i < M - 1)
            printf("\n");
    }
}

void sort(int **matrix, int M, int N) {
    int *tmp;
    int tmp_sum;
    int *sums = (int*) calloc(M, sizeof(int));
    int sum;
    for (int i = 0; i < M; i++) {
        sum = 0;
        for (int j = 0; j < N; j++) {
            sum += matrix[i][j];
        }
        sums[i] = sum;
    }
    for (int i = 0; i < M - 1; i++) {
        for (int j = 0; j < M - i - 1; j++) {
            if (sums[j] > sums[j + 1]) {
                tmp = matrix[j];
                matrix[j] = matrix[j + 1];
                matrix[j + 1] = tmp;
                tmp_sum = sums[j];
                sums[j] = sums[j + 1];
                sums[j + 1] = tmp_sum;
            }
        }
    }
    free(sums);
}
