#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "data_io.h"
#include "graph.h"
#include <string.h>
#include "translate.h"
#include "stack_double.h"
#include "string_parsing.h"
#include "stack.h"
#include "list.h"


int main() {
    char* data = input();
    rewrite_functions(&data);
    rewrite_minus_unar(&data);
    char** field = init_field();
    field = build_graph(field, data);
    show_field(field);
    destroy_field(field);
    free(data);
    return 0;
}


struct func_result f(double x, char * s) {
    char * st = (char*)malloc((1000) * sizeof(char));
    strcpy(st, s);
    substitution(&st, x);
     struct node *dict = init_list('(', 0);
    struct node * elem = add_symbol_list(dict, '+', 1);
    elem = add_symbol_list(elem, '-', 1);
    elem = add_symbol_list(elem, '*', 2);
    elem = add_symbol_list(elem, '/', 2);
    elem = add_symbol_list(elem, '^', 3);
    elem = add_symbol_list(elem, '~', 4);
    elem = add_symbol_list(elem, 's', 4);
    elem = add_symbol_list(elem, 'c', 4);
    elem = add_symbol_list(elem, 't', 4);
    elem = add_symbol_list(elem, 'q', 4);
    elem = add_symbol_list(elem, 'k', 4);
    elem = add_symbol_list(elem, 'l', 4);
    (void)elem;
    char *polish_string = malloc((int)strlen(st) * 10 * sizeof(char));
    translate(st, polish_string, dict);
    struct func_result resultix;
    resultix.resultat = 0;
    resultix.exist = 1;
    resultix = result(polish_string, dict, resultix);
    destroy_list(dict);
    free(st);
    free(polish_string);
    return resultix;
}

char** init_field() {
    char** field = (char**) malloc(H * sizeof(char*));
    for (int i = 0; i < H; i++) {
        field[i] = (char*) malloc(W * sizeof(char*));
    }
    for (int x = 0; x < W; x++) {
        for (int y = 0; y < H; y++) {
            field[y][x] = NOTHING;
        }
    }
    return field;
}

char **build_graph(char** field, char *s) {
    double dx = (XMAX - XMIN) / W;
    
    struct func_result function_values[W];
    if (1) {
        int i;
        double x;
        for (x = XMIN, i = 0; x <= XMAX && i < W; x += dx, i++) {
            function_values[i] = f(x, s);
        }
    }
    
    for (int x = 0; x < W; x++) {
        int y = (int) round((function_values[x].resultat - YMIN) * (H - 1) / (YMAX - YMIN));
        if (0 <= y && y < H && function_values[x].exist)
            field[y][x] = POINT;
    }
    return field;
}

void destroy_field(char** field) {
    if (field != NULL) {
        for (int i = 0; i < H; i++) {
            if (field[i] != NULL) {
                free(field[i]);
            }
        }
        free(field);
    }
}

void show_field(char** field) {
    for (int y = 0; y < H; y++) {
        for (int x = 0; x < W; x++) {
            printf("%c", field[y][x]);
        }
        printf("\n");
    }
}


void substitution(char **str, double arg) {
    char *var = (char*)malloc(1000 * sizeof(char));
    snprintf(var, 999, "%lf", arg);
    for (int i = 0; i < (int)strlen(*str); i++) {
        if ((*str)[i] == 'x') {
            char *tmp = realloc(*str,((int)strlen(*str) + (int)strlen(var)) * sizeof(char));
            if (tmp != NULL) {
                *str = tmp;
            } else {
                printf("No memory");
            }
            for (int j = (int)strlen(*str); j > i; j--) {
                (*str)[j + (int)strlen(var) - 1] = (*str)[j];
            }
            for (int j = 0; j < (int)strlen(var); j++) {
                (*str)[i + j] = var[j];
            }
        }
    }
    free(var);
}

