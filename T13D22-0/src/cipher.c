#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

int choice_1(char* path);
int choice_2(char* path);
int choice_3(char* path);
int input_choice(int* choice);
int input_path(char* path);
char* input_string_to_write(char* string_to_write);
void output_txt_file(FILE* txt_file, int* is_not_empty);
void clean(char* path_to_file);
int encrypt(char* path_to_file, int shift);

int main() {
    int choice = 0;
    int is_exit = 0;
    int is_valid = 1;
    char path[100];

    while (!is_exit) {
        is_valid = input_choice(&choice);
        if (is_valid && choice == 1) {
            is_valid = choice_1(path);
        } else if (is_valid && choice == 2) {
            is_valid = choice_2(path);
        } else if (is_valid && choice == 3) {
            is_valid = choice_3(path);
        } else if (is_valid && choice == -1) {
            is_exit = 1;
        } else if (!is_valid) {
            char test[100];
            scanf("%s", test);
        }
        if (!is_valid) {
            printf("n/a\n");
        }
    }
    return 0;
}

int choice_1(char* path) {
    int is_valid = 1;
    int is_not_empty = 0;
    FILE *txt_file = NULL;

    if (!input_path(path)) {
        is_valid = 0;
    }
    if (is_valid) {
        txt_file = fopen(path, "r");
    }
    if (txt_file == NULL) {
        is_valid = 0;
    }
    if (is_valid) {
        output_txt_file(txt_file, &is_not_empty);
        fclose(txt_file);
    }
    printf("\n");
    return is_valid && is_not_empty;
}

int choice_2(char* path) {
    int is_valid = 1;
    int is_not_empty = 0;
    FILE* txt_file = NULL;
    char* string_to_write = NULL;

    if (is_valid) {
        txt_file = fopen(path, "a");
    }
    if (txt_file == NULL) {
        is_valid = 0;
    }
    string_to_write = input_string_to_write(string_to_write);
    if (is_valid) {
        fprintf(txt_file, "\n%s", string_to_write);
        fclose(txt_file);
        txt_file = fopen(path, "r");
        output_txt_file(txt_file, &is_not_empty);
        fclose(txt_file);
    }
    if (string_to_write != NULL) {
        free(string_to_write);
    }
    printf("\n");
    return is_valid && is_not_empty;
}

int choice_3(char* path) {
    int is_valid = 1;
    int shift;
    struct dirent* file;
    char* path_to_file = (char*) malloc(100 * sizeof(char));
    DIR* dir;

    if (!input_path(path)) is_valid = 0;
    if (is_valid) dir = opendir(path);
    if (dir == NULL) is_valid = 0;
    is_valid = input_choice(&shift);
    if (is_valid) {
        while ((file = readdir(dir)) != NULL) {
            strcpy(path_to_file, path);
            path_to_file = strcat(strcat(path_to_file, "/"), file->d_name);
            if (path_to_file[strlen(path_to_file) - 2] == '.' &&
                    path_to_file[strlen(path_to_file) - 1] == 'h') {
                clean(path_to_file);
            }
            if (path_to_file[strlen(path_to_file) - 2] == '.' &&
                    path_to_file[strlen(path_to_file) - 1] == 'c') {
                is_valid = encrypt(path_to_file, shift);
            }
        }
        closedir(dir);
    }
    if (path_to_file != NULL) free(path_to_file);
    return is_valid;
}

int input_choice(int* choice) {
    int is_valid = 1;
    if (!scanf("%d", choice)) {
        is_valid = 0;
    }
    getchar();
    return is_valid;
}

int input_path(char* path_txt_file) {
    int is_valid = 1;
    if (!scanf("%s", path_txt_file)) {
        is_valid = 0;
    }
    return is_valid;
}

char* input_string_to_write(char* string_to_write) {
    char buffer = '\0';
    int i = 0;
    int size = 0;
    while (buffer != '\n') {
        if (scanf("%c", &buffer) && buffer != '\n') {
            size++;
            char *tmp = (char*) realloc(string_to_write, size * sizeof(char));
            if (tmp != NULL) {
                string_to_write = tmp;
                string_to_write[i] = buffer;
            }
        }
        i++;
    }
    if (size) {
        size++;
        char *tmp = (char*) realloc(string_to_write, size * sizeof(char));
        if (tmp != NULL) {
            string_to_write = tmp;
            string_to_write[size - 1] = '\0';
        }
    }
    return string_to_write;
}

void output_txt_file(FILE* txt_file, int* is_not_empty) {
    char out = '\0';
    while ((out = getc(txt_file)) != EOF) {
        printf("%c", out);
        (*is_not_empty)++;
    }
    if (is_not_empty) {
        printf("\n");
    }
}

void clean(char* path_to_file) {
    FILE* file = fopen(path_to_file, "w");
    if (file != NULL) fclose(file);
}

int encrypt(char* path_to_file, int shift) {
    int is_valid = 1;
    char* file_content = NULL;
    FILE* file = fopen(path_to_file, "r");
    if (file == NULL) is_valid = 0;
    int size = 0;
    char buffer;
    while ((buffer = getc(file)) != EOF && is_valid) {
        size++;
        char *tmp = (char*) realloc(file_content, size * sizeof(char));
        if (tmp != NULL) {
            file_content = tmp;
            file_content[size - 1] = buffer;
        }
    }
    fclose(file);
    if (size) {
        size++;
        char *tmp = (char*) realloc(file_content, size * sizeof(char));
        if (tmp != NULL) {
            file_content = tmp;
            file_content[size - 1] = '\0';
        }
    }
    int i = 0;
    file = fopen(path_to_file, "w");
    while (file_content[i] != '\0') {
        fputc(file_content[i] + shift, file);
        i++;
    }
    fclose(file);
    if (file_content != NULL) {
        free(file_content);
    }
    return is_valid;
}
