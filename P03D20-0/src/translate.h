#ifndef SRC_TRANSLATE_H_
#define SRC_TRANSLATE_H_

struct func_result{
    double resultat;
    int exist;
};

void translate(char *s, char *polish_string, struct node *dict);
struct func_result result(char * polish_string, struct node *dict, struct func_result result);
struct func_result math_operations(char op, double first, double second, struct func_result result);

#endif  // SRC_TRANSLATE_H_


