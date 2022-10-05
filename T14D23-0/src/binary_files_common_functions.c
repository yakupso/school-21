#include <stdio.h>
#include <stdlib.h>

#include "./binary_files_common_functions.h"

struct record read_record_from_file(FILE *pfile, int index) {
    int offset = index * sizeof(struct record);
    fseek(pfile, offset, SEEK_SET);
    struct record record;
    fread(&record, sizeof(struct record), 1, pfile);
    rewind(pfile);
    return record;
}

void write_record_in_file(FILE *pfile, const struct record *record_to_write, int index) {
    int offset = index * sizeof(struct record);
    fseek(pfile, offset, SEEK_SET);
    fwrite(record_to_write, sizeof(struct record), 1, pfile);
    fflush(pfile);
    rewind(pfile);
}

void swap_records_in_file(FILE *pfile, int record_index1, int record_index2) {
    struct record record1 = read_record_from_file(pfile, record_index1);
    struct record record2 = read_record_from_file(pfile, record_index2);

    write_record_in_file(pfile, &record1, record_index2);
    write_record_in_file(pfile, &record2, record_index1);
}

int get_file_size_in_bytes(FILE *pfile) {
    int size = 0;
    fseek(pfile, 0, SEEK_END);
    size = ftell(pfile);
    rewind(pfile);
    return size;
}

int get_records_count_in_file(FILE *pfile) {
    return get_file_size_in_bytes(pfile) / sizeof(struct record);
}
