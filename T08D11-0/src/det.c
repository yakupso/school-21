double det(double **matrix, int n, int m);
void input(double **matrix, int *n, int *m);
void output(double det);

int main() {
    int **matrix;
    int n, m;
    
    if (input(matrix, &n, &m)) {
        double det_v = det(matrix, n, m);
        output(det_v);
    }
    
    return 0;
}

int input(int **matrix, int *n, int *m) {
    int is_valid = 1;
    char c;
    
    if (!(scanf("%d %d%c", n, m, &c) == 3 && c == '\n' && *n == *m)) {
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

double det(int **matrix, int n, int m) {
    
}
