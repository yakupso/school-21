#include "list.h"
#include "stack.h"
#include "string_parsing.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "translate.h"
#include <math.h>
#include "stack_double.h"

void translate(char *s, char *polish_string, struct node *dict) {
    struct stack *stek = init('n');
    int j = 0;
    for (int i = 0; i < (int)strlen(s); i++) {
        char c = s[i];
        if (in_double(c)) {
            read_number(s, polish_string, &j, &i);
            if (i != '\0'){
                polish_string[j] = ' ';
                j++;
                i--;
            } else {
                polish_string[j] = '\0';
            }
        } else if (c == '(') {
            stek = push(stek, c);
        } else if (c == ')') {
            while (stek -> value != '(') {
                    polish_string[j] = stek -> value;
                    j++;
                    polish_string[j] = ' ';
                    j++;
                    stek = pop(stek);
            }
            stek = pop(stek);
            if (s[i + 1] == '\0' && stek -> prev == NULL) {
                j--;
                polish_string[j] = '\0';
            } else {
            }
        } else if(find_list(c, dict)) {
                while (stek -> prev != NULL && (find_list(stek -> value, dict) >= find_list(c, dict))) {
                    polish_string[j] = stek -> value;
                    j++;
                    polish_string[j] = ' ';
                    j++;
                    stek = pop(stek);
                }
                stek = push(stek, c);
        }
    }
    while(stek -> prev != NULL) {
        if ((stek -> prev) -> prev == NULL) {
            polish_string[j] = stek -> value;
            j++;
            polish_string[j] = '\0';
            stek = pop(stek);
        } else {
            polish_string[j] = stek -> value;
            j++;
            polish_string[j] = ' ';
            j++;
            stek = pop(stek);
        }
    }
    destroy(stek);
}

struct func_result result(char * polish_string, struct node *dict, struct func_result result) {
    struct stack_double *stek = NULL;
    result.resultat = 0;
    result.exist = 1;
    for (int i = 0; i < (int)strlen(polish_string); i++) {
        if(result.exist == 1) {
            char c = polish_string[i];
            if (c == ' ') {
            } else if (in_double(c)) {
                stek = push_double(stek, read_number_double(polish_string, &i));
            } else if(find_list(c, dict)) {
                if (in_char_unary(c)) {
                    double sec = stek -> value;
                    stek = pop_double(stek);
                    result = math_operations(c, 0, sec, result);
                    stek = push_double(stek, result.resultat);
                } else {
                    double sec = stek -> value;
                    stek = pop_double(stek);
                    double fir = stek -> value;
                    stek = pop_double(stek);
                    result = math_operations(c, fir, sec, result);
                    stek = push_double(stek, result.resultat);
                }
            }
        } else {
            i = (int)strlen(polish_string);
        }
    }
    if(stek != NULL && stek -> prev == NULL) {
        result.resultat = stek -> value;
    }
    destroy_double(stek);
    return result;
}


struct func_result math_operations(char op, double first, double second, struct func_result result) {
    result.resultat = 0;
    result.exist = 1;
    if (op == '+') {
        result.resultat = first + second;
    } else if (op == '-') {
        result.resultat = first - second;
    } else if (op == '*') {
        result.resultat = first * second;
    } else if (op == '/') {
        if (second != 0) {
            result.resultat = first / second;
        } else {
            result.resultat = 0;
            result.exist = 0;
        }
    } else if (op == '~') {
        result.resultat = first - second;
    }  else if (op == '^') {
        result.resultat = pow(first, second);
    }  else if (op == 's') {
        result.resultat = first + sin(second);
    } else if (op == 'c') {
        result.resultat = first + cos(second);
    } else if (op == 't') {
        if (second != M_PI / 2.0 && second != M_PI * 3 / 2 && second != M_PI * 5 / 2
            && second != M_PI * 7 / 2) {
            result.resultat = first + tan(second);
        } else {
            result.resultat = 0;
            result.exist = 0;
        }
    } else  if (op == 'q') {
        if (second != 0 && second != M_PI * 1 && second != M_PI * 2
            && second != M_PI * 3 && second != M_PI * 4) {
            result.resultat = first + 1 / tan(second);
        } else {
            result.resultat = 0;
            result.exist = 0;
        }
    } else if (op == 'k') {
        if (second >= 0) {
            result.resultat = first + sqrt(second);
        } else {
            result.resultat = 0;
            result.exist = 0;
        }
    } else if (op == 'l') {
        if (second > 0) {
            result.resultat = first + log(second);
        } else {
            result.resultat = 0;
            result.exist = 0;
        }
    }
    return result;
}



