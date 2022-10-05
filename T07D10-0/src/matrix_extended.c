#include <stdio.h>
#include <stdlib.h>

#define MAXSZ 100

int menu();
void choice_1(int M, int N);
void choice_2(int M, int N);
void choice_3(int M, int N);
void choice_4(int M, int N);
int input_size(int *M, int *N);
int input_matrix(int **matrix, int M, int N);
void output_matrix(int **matrix, int M, int N);
void output_arr(int *arr, int N);
void find_max(int **matrix, int M, int N, int *max);
void find_min(int **matrix, int M, int N, int *min);

int main() {
    int M, N;
    int choice = menu();
    if (choice && input_size(&M, &N) && M > 0 && N > 0) {
        if (choice == 1 && M <= MAXSZ && N <= MAXSZ) {
            choice_1(M, N);
        } else if (choice == 2) {
            choice_2(M, N);
        } else if (choice == 3) {
            choice_3(M, N);
        } else if (choice == 4) {
            choice_4(M, N);
        }
    } else {
        printf("n/a");
    }
    return 0;
}

void choice_1(int M, int N) {
    int static_matrix[MAXSZ][MAXSZ];
    for (int i = 0; i < MAXSZ; i++) {
        for (int j = 0; j < MAXSZ; j++) {
            static_matrix[i][j] = 0;
        }
    }
    int* aux_matrix[MAXSZ];
    for (int i = 0; i < MAXSZ; i++) {
        aux_matrix[i] = static_matrix[i];
    }
    if (input_matrix(aux_matrix, M, N)) {
        int max[MAXSZ];  // M
        int min[MAXSZ];  // N
        output_matrix(aux_matrix, M, N);
        find_max(aux_matrix, M, N, max);
        find_min(aux_matrix, M, N, min);
        output_arr(max, M);
        output_arr(min, N);
    } else {
        printf("n/a");
    }
}

void choice_2(int M, int N) {
    int** single_array_matrix = malloc(M * N * sizeof(int) + M * sizeof(int*));
    int* ptr = (int*) (single_array_matrix + M);
    for (int i = 0; i < M; i++)
        single_array_matrix[i] = ptr + N * i;
    if (input_matrix(single_array_matrix, M, N)) {
        int max[MAXSZ];  // M
        int min[MAXSZ];  // N
        output_matrix(single_array_matrix, M, N);
        find_max(single_array_matrix, M, N, max);
        find_min(single_array_matrix, M, N, min);
        output_arr(max, M);
        output_arr(min, N);
    } else {
        printf("n/a");
    }
    free(single_array_matrix);
}

void choice_3(int M, int N) {
    int** pointer_array = malloc(M * sizeof(int*));
    for (int i = 0; i < M; i++)
        pointer_array[i] = malloc(N * sizeof(int));
    for (int i = 0; i < M; i++)
        free(pointer_array[i]);
    if (input_matrix(pointer_array, M, N)) {
        int max[MAXSZ];  // M
        int min[MAXSZ];  // N
        output_matrix(pointer_array, M, N);
        find_max(pointer_array, M, N, max);
        find_min(pointer_array, M, N, min);
        output_arr(max, M);
        output_arr(min, N);
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
        int max[MAXSZ];  // M
        int min[MAXSZ];  // N
        output_matrix(pointer_array, M, N);
        find_max(pointer_array, M, N, max);
        find_min(pointer_array, M, N, min);
        output_arr(max, M);
        output_arr(min, N);
    } else {
        printf("n/a");
    }
    free(values_array);
    free(pointer_array);
}

int menu() {
    int choice;
    char c;
    if (!(scanf("%d%c", &choice, &c) == 2 && c == '\n')) {
        choice = 0;
    }
    return choice;
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

void output_arr(int *arr, int N) {
    printf("\n");
    for (int i = 0; i < N; i++) {
        if (i < N - 1) {
            printf("%d ", arr[i]);
        } else {
            printf("%d", arr[i]);
        }
    }
}

void find_max(int **matrix, int M, int N, int *max) {
    int max_v;
    for (int i = 0; i < M; i++) {
        max_v = matrix[i][0];
        for (int j = 0; j < N; j++) {
            if (matrix[i][j] >= max_v) {
                max_v = matrix[i][j];
            }
        }
        max[i] = max_v;
    }
}

void find_min(int **matrix, int M, int N, int *min) {
    int min_v;
    for (int j = 0; j < N; j++) {
        min_v = matrix[0][j];
        for (int i = 0; i < M; i++) {
            if (matrix[i][j] <= min_v) {
                min_v = matrix[i][j];
            }
        }
        min[j] = min_v;
    }
}
