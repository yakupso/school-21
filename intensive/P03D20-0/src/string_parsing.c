#include "string_parsing.h"


void rewrite_minus_unar(char ** str) {
    int i = 0;
    while(i < (int)strlen(*str)) {
        if((*str)[i] == '-' && i == 0) {
            (*str)[i] = '~';
        } else if ((*str)[i] == '-' && in_char((*str)[i - 1])) {
            (*str)[i] = '~';
        } else {
        }
        i++;
    }
}

void rewrite_functions(char **str) {
    char *var;
    while (strstr(*str, "sin") != NULL) {
        var = strstr(*str, "sin");
        rewrite_str(str, var, 3, 's');
    }
    while (strstr(*str, "cos") != NULL) {
        var = strstr(*str, "cos");
        rewrite_str(str, var, 3, 'c');
    }
    while (strstr(*str, "tan") != NULL) {
        var = strstr(*str, "tan");
        rewrite_str(str, var, 3, 't');
    }
    while (strstr(*str, "ctg") != NULL) {
        var = strstr(*str, "ctg");
        rewrite_str(str, var, 3, 'q');
    }
    while (strstr(*str, "sqrt") != NULL) {
        var = strstr(*str, "sqrt");
        rewrite_str(str, var, 4, 'k');
    }
    while (strstr(*str, "ln") != NULL) {
        var = strstr(*str, "ln");
        rewrite_str(str, var, 2, 'l');
    }
}

void rewrite_str(char **str, char *var, int count, char c) {
    var[0] = c;
    int i = 1;
    while (var[i + count - 1] != '\0') {
        var[i] = var[i + count - 1];
        i++;
    }
    var[i] = '\0';
    char *tmp = realloc(*str, (strlen(*str) + 1) * sizeof(char));
    if (tmp != NULL) {
        *str = tmp;
    } else {
        printf("No memory");
    }
}

void read_number(char *str, char *polishstr, int *j, int *i) {
    while(in_double(str[*i])) {
        polishstr[*j] = str[(*i)];
        (*i)++;
        (*j)++;
    }
}

int in_double(char c) {
    int flag = 0;
    if (c == '0' || c == '1' || c == '2' || c == '3' ||
    c == '4' || c == '5' || c == '6' ||
    c == '7' || c == '8'||  c == '9' || c == '.') {
        flag = 1;
    }
    return flag;
}

int in_char(char c) {
    int flag = 0;
    if (c == '+' || c == '-' || c == '(' || c == '*' ||
    c == 's' || c == 'c' || c == 't' ||
    c == 'q' || c == 'k' || c == 'l' || c == '/' || c == ')') {
        flag = 1;
    }
    return flag;
}


double read_number_double(char *polishstr, int *i) {
    char *var = (char*)malloc(1000 * sizeof(char));
    int j = 0;
    while (in_double(polishstr[*i])) {
        var[j] = polishstr[(*i)];
        (*i)++;
        j++;
    }
    var[j] = '\0';
    double func = 0;
    func = strtod(var,&var);
    return func;
}

int in_char_unary(char c) {
    int flag = 0;
    if (c == 's' || c == 'c' || c == 't' ||
    c == 'q' || c == 'k' || c == 'l' || c == '~') {
        flag = 1;
    }
    return flag;
}
