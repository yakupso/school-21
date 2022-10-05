#include <stdio.h>
#include <stdlib.h>

#include "data_io.h"

char* input() {
    int size = 0;
    char* data = NULL;
    char buffer = '\0';
    
    int i = 0;
    while (buffer != '\n') {
        if (scanf("%c", &buffer)) {
            size++;
            char *tmp = (char*) realloc(data, size * sizeof(char));
            if (buffer != '\n') {
                if (tmp != NULL) {
                    data = tmp;
                    data[i] = buffer;
                } else {
                    
                }
            } else {
                if (tmp != NULL) {
                    data = tmp;
                    data[i] = '\0';
                } else {
                    
                }
            }
        }
        i++;
    }
    return data;
}
