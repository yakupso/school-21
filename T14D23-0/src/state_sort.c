#include <stdio.h>
#include <string.h>

#include "./binary_files_common_functions.h"

int choice_0(char* path);
int choice_1(char* path);
int choice_2(char* path);
int input_choice(int* choice);
int input_path(char* path);
void output_file(FILE* file, int* is_not_empty);
void output_record(struct record record);
int is_bigger(struct record record_1, struct record record_2);
void bubble_sort(FILE* file, int* is_not_empty);

int main() {
    int choice = 0;
    int is_valid = 1;
    char path[255] = {0};
    char full_path[255] = "../";
    is_valid = input_path(path) && input_choice(&choice);
    if (is_valid) strcat(full_path, path);

    if (is_valid && choice == 0)
        is_valid = choice_0(full_path);
    else if (is_valid && choice == 1)
        is_valid = choice_1(full_path);
    else if (is_valid && choice == 2)
        is_valid = choice_2(full_path);
    else
        is_valid = 0;

    if (!is_valid) printf("n/a\n");

    return 0;
}

int choice_0(char* path) {
    int is_valid = 1;
    int is_not_empty = 0;
    FILE *file = NULL;

    if (is_valid) file = fopen(path, "rb");
    if (file == NULL) is_valid = 0;
    if (is_valid) {
        output_file(file, &is_not_empty);
        fclose(file);
    }
    if (is_valid && is_not_empty) printf("\n");
    return is_valid && is_not_empty;
}

int choice_1(char* path) {
    int is_valid = 1;
    int is_not_empty = 0;

    FILE *file = NULL;

    if (is_valid) file = fopen(path, "r+b");
    if (file == NULL) is_valid = 0;
    if (is_valid) {
        bubble_sort(file, &is_not_empty);
        fclose(file);
    }
    if (is_valid && is_not_empty) printf("\n");

    return is_valid && is_not_empty;
}

int choice_2(char* path) {
    int is_valid = 1;
    int is_not_empty = 0;
    FILE *file = NULL;
    struct record new_record;
    if (!scanf("%d", &new_record.year)) is_valid = 0;
    if (!(scanf("%d", &new_record.mounth) && new_record.mounth <= 12)) is_valid = 0;
    if (!(scanf("%d", &new_record.day) && new_record.day <= 31)) is_valid = 0;
    if (!(scanf("%d", &new_record.hour) && new_record.hour <= 24)) is_valid = 0;
    if (!(scanf("%d", &new_record.minute) && new_record.minute <= 60)) is_valid = 0;
    if (!(scanf("%d", &new_record.second) && new_record.second <= 60)) is_valid = 0;
    if (!(scanf("%d", &new_record.status) &&
                    (new_record.status == 1 || new_record.status == 0)))
        is_valid = 0;
    if (!scanf("%d", &new_record.code)) is_valid = 0;

    if (is_valid) file = fopen(path, "ab");
    if (file == NULL) is_valid = 0;
    if (is_valid) {
        write_record_in_file(file, &new_record, get_records_count_in_file(file) + 1);
        file = fopen(path, "r+b");
        bubble_sort(file, &is_not_empty);
        fclose(file);
        file = fopen(path, "rb");
        output_file(file, &is_not_empty);
        fclose(file);
    }

    return is_valid && is_not_empty;
}

int input_choice(int* choice) {
    int is_valid = 1;
    if (!scanf("%d", choice)) {
        is_valid = 0;
    }
    getchar();
    return is_valid;
}

int input_path(char* path) {
    int is_valid = 1;
    if (!scanf("%s", path)) {
        is_valid = 0;
    }
    return is_valid;
}

void output_file(FILE* file, int* is_not_empty) {
    int size = get_records_count_in_file(file);
    *(is_not_empty) = size ? 1 : 0;
    for (int i = 0; i < size; i++) {
        output_record(read_record_from_file(file, i));
        if (i < size - 1) printf("\n");
    }
}

void output_record(struct record record) {
    printf("%d %d %d %d %d %d %d %d",
            record.year,
            record.mounth,
            record.day,
            record.hour,
            record.minute,
            record.second,
            record.status,
            record.code);
}

int is_bigger(struct record record_1, struct record record_2) {
    long int record_sum_1 = (record_1.year * 10000000000 +
                        record_1.mounth * 100000000 +
                        record_1.day * 1000000 +
                        record_1.hour * 10000 +
                        record_1.minute * 100 +
                        record_1.second * 1);
    long int record_sum_2 = (record_2.year * 10000000000 +
                        record_2.mounth * 100000000 +
                        record_2.day * 1000000 +
                        record_2.hour * 10000 +
                        record_2.minute * 100 +
                        record_2.second * 1);
    return record_sum_1 > record_sum_2 ? 1 : 0;
}

void bubble_sort(FILE* file, int* is_not_empty) {
    int size = get_records_count_in_file(file);
    *(is_not_empty) = size ? 1 : 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            struct record record_1 = read_record_from_file(file, j);
            struct record record_2 = read_record_from_file(file, j + 1);
            if (is_bigger(record_1, record_2)) {
                swap_records_in_file(file, j, j + 1);
            }
        }
    }
}
