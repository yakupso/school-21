#include <stdio.h>
#include <stdlib.h>

#define MAXSZ 100

int menu();
int input_size(int *M, int *N);
int input_matrix(int **matrix, int M, int N);
void output_matrix(int **matrix, int M, int N);
int sum(int **matrix_first, int n_first, int m_first, int **matrix_second,
    int n_second, int m_second, int **matrix_result, int *n_result, int *m_result);
int transpose(int **matrix, int n, int m);
int mul(int **matrix_first, int n_first, int m_first, int **matrix_second,
    int n_second, int m_second, int **matrix_result, int *n_result, int *m_result);

int main() {
    int M_1, N_1, M_2, N_2;
    int choice = menu();
    if (choice && input_size(&M_1, &N_1) && input_size(&M_1, &N_1) && M_1 > 0 && N_1 > 0) {
        if (choice == 1 && M_1 <= 100 && N_1 <= 100) {
            int** matrix_1 = malloc(M_1 * N_1 * sizeof(int) + M_1 * sizeof(int*));
            int* ptr = (int*) (matrix_1 + M_1);
            for (int i = 0; i < M_1; i++)
                matrix_1[i] = ptr + N_1 * i;
            
            int** matrix_2 = malloc(M_2 * N_2 * sizeof(int) + M_2 * sizeof(int*));
            int* ptr = (int*) (matrix_2 + M_2);
            for (int i = 0; i < M_2; i++)
                matrix_2[i] = ptr + N_2 * i;
            if (input_matrix(matrix_2, M_2, N_2)) {
                
                output_matrix(matrix_2, M_2, N_2);
            }
            free(matrix_1);
            free(matrix_2);
        } else {
            printf("n/a");
        }
    }
    return 0;
}

int menu() {
    int choice;
    char c;
    if (!(scanf("%d%c", &choice, &c) == 2 && c == '\n' && choice > 0 && choice < 4)) {
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
