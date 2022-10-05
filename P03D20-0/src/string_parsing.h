#ifndef SRC_STRING_PARSING_H_
#define SRC_STRING_PARSING_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void rewrite_minus_unar(char ** str);
void rewrite_functions(char **str);
void rewrite_str(char **str, char *var, int count, char c);
void read_number(char *str, char *polishstr, int *j, int *i);
int in_double(char c);
int in_char(char c);
double read_number_double(char *polishstr, int *i);
int in_char_unary(char c);

#endif  // SRC_STRING_PARSING_H_
