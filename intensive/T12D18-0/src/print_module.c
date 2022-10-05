#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "print_module.h"

char* printchar() {
    const time_t timer = time(NULL);
    struct tm *local_time;
    local_time = localtime(&timer);
    char* result = (char*) malloc(9 * sizeof(char));
    strftime(result, 9, "%X", local_time);
    return result;
}

void print_log(char* (*printchar)(void), char* message) {
    char* curr_time = printchar();
    printf("%s %s %s", Log_prefix, curr_time, message);
    free(curr_time);
}


