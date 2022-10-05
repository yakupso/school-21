#include <stdlib.h>

#include "./data_io.h"
#include "./graph.h"

int main() {
    char* data = input();
    output(data);
    char** field = init_field();
    field = build_graph(field);
    show_field(field);
    reverse_show_field(field);
    destroy_field(field);
    //free(data);
    
    return 0;
}
