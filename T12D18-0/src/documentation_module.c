#include "documentation_module.h"
#include <stdarg.h>
#include <stdlib.h>

int validate(char* data) {
    int validation_result = !strcmp(data, Available_document);
    return validation_result;
}

int* check_available_documentation_module(int(*validate) (char*), int document_count, ...) {
    int *documents_status = NULL;
    if (document_count > 0) {
        documents_status = (int *) malloc(document_count * sizeof(int));
        va_list documents;
        va_start(documents, document_count);
        for (int i = 0; i < document_count; i++) {
            documents_status[i] = validate(va_arg(documents, char*));
        }
        va_end(documents);
    }
    return documents_status;
}
