#include <stdio.h>
#include <string.h>

#include "./binary_files_common_functions.h"

int input_path(char* path);
int input_record(struct record* required_record);
int is_equal(struct record record_1, struct record record_2);
int find_elem(struct record required_record, char* path);

int main() {
    int is_valid = 0;
    char path[255] = {0};
    char full_path[255] = "../";
    is_valid = input_path(path);
    if (is_valid != -1) strcat(full_path, path);
    struct record required_record;
    if (!input_record(&required_record)) is_valid = 0;
    if (is_valid != -1) {
        is_valid = find_elem(required_record, full_path);
    }
    if (is_valid != -1) {
        printf("%d", is_valid);
    } else {
        printf("n/a");
    }

    return 0;
}

int input_path(char* path) {
    int is_valid = 1;
    if (!scanf("%s", path)) {
        is_valid = -1;
    }
    return is_valid;
}

int input_record(struct record* required_record) {
    int is_valid = 1;
    if (!scanf("%2d.%2d.%4d", &required_record->day,
                              &required_record->mounth,
                              &required_record->year))
        is_valid = -1;

    return is_valid;
}

int is_equal(struct record record_1, struct record record_2) {
    long int record_sum_1 = (record_1.year * 10000000000 +
                        record_1.mounth * 100000000 +
                        record_1.day * 1000000);
    long int record_sum_2 = (record_2.year * 10000000000 +
                        record_2.mounth * 100000000 +
                        record_2.day * 1000000);
    return record_sum_1 == record_sum_2 ? 1 : 0;
}

int find_elem(struct record required_record, char* path) {
    int is_valid = 0;
    int not_found_yet = 1;
    FILE* file = NULL;
    if (is_valid != -1) file = fopen(path, "rb");
    if (file == NULL) is_valid = -1;
    if (is_valid != -1) {
        int size = get_records_count_in_file(file);
        for (int i = 0; i < size && not_found_yet; i++) {
            struct record curr_record = read_record_from_file(file, i);
            if (is_equal(required_record, curr_record)) {
                not_found_yet = 0;
                is_valid = curr_record.code;
            }
        }
        fclose(file);
    }
    if (not_found_yet) is_valid = -1;
    return is_valid;
}
