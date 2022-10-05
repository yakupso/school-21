#include <stdio.h>
#include <stdlib.h>
/*
    1 6 7
    2 5 8
    3 4 9
*/
void sort_vertical(int **matrix, int n, int m, int **result_matrix);

/*
    1 2 3
    6 5 4
    7 8 9
*/
void sort_horizontal(int **matrix, int n, int m, int **result_matrix);


int input(int **matrix, int *n, int *m);
void output(int **matrix, int n, int m);


int main() {
    int **matrix, **result;
    int n, m;
    
    if (input(matrix, &n, &m)) {
    
        //sort_vertical(matrix, n, m, result);
        //output(result);
    
        //sort_horizontal(matrix, n, m, result);
        //output(result);
    }
    return 0;
}

void sort_bubble(int **matrix, int n, int m) {
    
}

void sort_horizontal(int **matrix, int n, int m, int **result_matrix) {
    
}

int input(int **matrix, int *n, int *m) {
    int is_valid = 1;
    char c;
    
    if (!(scanf("%d %d%c", n, m, &c) == 3 && c == '\n')) {
        is_valid = 0;
    }
    matrix = (int**) calloc(*n, sizeof(int));
    for (int i = 0; i < *n; i++) {
        matrix[i] = (int*) calloc(*m, sizeof(int));
    }
    
    for (int i = 0; i < *n && is_valid; i++) {
        for (int j = 0; j < *m && is_valid; j++) {
            if (!(scanf("%d%c", &matrix[i][j], &c) == 2 && (c == '\n' || c == ' '))) {
                is_valid = 0;
            }
        }
    }
    return is_valid;
}
